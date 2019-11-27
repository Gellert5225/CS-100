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
#include "ParseFactory.hpp"
#include "ParseTestCommand.hpp"
#include "ParsePrecedence.hpp"

void parse(const std::string &cmdLine, CommandLine &result);

void integration_test(int argc, char** argv);

int main(int argc, char** argv) {
    // for integration test only
    if (argc > 1 && strcmp(argv[1], "integration_test") == 0) {
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
        cl.execute();
    }
    
    return 0;
}

void parse(const std::string &cmdLine, CommandLine &result) {
    std::istringstream iss(cmdLine);

    std::vector<std::string> buffer;
    std::string arg;

    Base* root = nullptr;
    Base* parsedResult = nullptr;

    Connector* c;
    bool commented = false;
    ParseFactory* parseFactory;

    std::string regCmds = "";
    std::string testCmds = "";
    bool isTestCmd = false;

    while (iss >> arg) {
        if (commented) break;
        bool endOfCmd = false;
        c = nullptr;

        if (arg.front() == '#') {
            endOfCmd = true;
            commented = true;
        } else if (arg.front() == '[' || arg == "test") {
            // test commands
            isTestCmd = true;
            while (arg != "]" && iss >> arg) {
                if (arg != "]") testCmds += arg + " ";
            }
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
            regCmds += arg + " ";
        }

        if (iss.eof()) {endOfCmd = true;}

        if (endOfCmd) {
            if (isTestCmd) {
                parseFactory = new ParseTestCommand();
                parsedResult = parseFactory->parse(testCmds);
                testCmds = "";
                isTestCmd = false;
            } else {
                parseFactory = new ParsePrecedence();
                parsedResult = parseFactory->parse(regCmds);
                regCmds = "";
            }
            if (root == nullptr) {
                if (c == nullptr) root = parsedResult;
                else {
                    root = c;
                    c->setLeft(parsedResult);
                }
            } else {
                if (c != nullptr) {
                    Base* temp = root;
                    c->setLeft(temp);
                    reinterpret_cast<Connector*>(temp)->setRight(parsedResult);
                    root = c;
                } else {
                    reinterpret_cast<Connector*>(root)->setRight(parsedResult);
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
