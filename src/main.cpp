#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include <sstream>
#include <iostream>
#include <vector>
#include "Base.hpp"
#include "CommandLine.hpp"
#include "Command.hpp"
#include "AndOrSemicolon.hpp"

void parse(const std::string &cmdLine, CommandLine &result);

void integration_test(int argc, char** argv);

int main(int argc, char** argv) {
    // for integration test only
    if (strcmp(argv[1], "integration_test") == 0) {
        integration_test(argc, argv);
        return 0;
    }

    char* userName = getlogin();
    char hostName[256] = "/0";
    gethostname(hostName, 256);

    while (true) {
        std::cout << userName << "@" << hostName << "$ ";

        std::string cmd = "";
        std::getline(std::cin, cmd);
        CommandLine cl;

        parse(cmd, cl);
        reinterpret_cast<Connector*>(cl.b)->execute();
    }
    
    return 0;
}

void parse(const std::string &cmdLine, CommandLine &result) {
    std::istringstream iss(cmdLine);

    std::vector<std::string> buffer;
    std::string arg;
    Base* root = nullptr;
    Connector* c;
    bool commented = false;

    while (iss >> arg) {
        if (commented) break;
        bool endOfCmd = false;
        c = nullptr;

        if (arg.front() == '#') {
            endOfCmd = true;
            commented = true;
        } else if (arg == "||") {
            c = new Or();
            endOfCmd = true;
        } else if (arg == "&&") {
            c = new And();
            endOfCmd = true;
        } else {
            if (arg.back() == ';') {
                arg = arg.substr(0, arg.size() - 1);
                endOfCmd = true;
                c = new Semicolon();
            }
            buffer.push_back(arg);
        }

        if (iss.eof()) {endOfCmd = true;}

        if (endOfCmd && buffer.size() != 0) {
            Command *cmd = new Command(buffer.size());
            std::vector<std::string> *cp = new std::vector<std::string>();
            *cp = buffer;
            cmd->setArgs(cp);
            buffer.clear();

            if (root == nullptr) {
                if (c == nullptr) root = cmd;
                else {
                    root = c;
                    c->setLeft(cmd);
                }
            } else {
                if (c != nullptr) {
                    Base* temp = root;
                    c->setLeft(temp);
                    reinterpret_cast<Connector*>(temp)->setRight(cmd);
                    root = c;
                } else {
                    reinterpret_cast<Connector*>(root)->setRight(cmd);
                }
            }
        }
        
    }

    if (root == nullptr) root = new Semicolon();
    result.b = root;
}

void integration_test(int argc, char** argv) {
    std::string cmd = "";
    for(int i = 2; i < argc; i++) {
        cmd += argv[i];
        cmd += " ";
    }
    cmd.pop_back();
    CommandLine cl;

    parse(cmd, cl);
    reinterpret_cast<Connector*>(cl.b)->execute();
}
