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

int main(int argc, char** argv) {
    std::string cmd = "echo true || ech wrong && echo yeah";
    CommandLine cl;

    /*
    std::vector<std::string> v1 = {"left"};
    std::vector<std::string> v2 = {"right"};
    Command* cmdLeft = new Command(1);
    Command* cmdRight = new Command(1);
    cmdLeft->setArgs(v1);
    cmdRight->setArgs(v2);

    Connector* c = new Semicolon();
    c->setLeft(cmdLeft);
    c->setRight(cmdRight);

    Base* root = c;
    */
    parse(cmd, cl);

    //std::cout << reinterpret_cast<Connector*>(cl.b)->getLeft()->toString() << std::endl;
    //std::cout << reinterpret_cast<Connector*>(cl.b)->getRight()->toString() << std::endl;

    //reinterpret_cast<Connector*>(cl.b)->getLeft()->execute();
    //reinterpret_cast<Connector*>(cl.b)->getRight()->execute();

    reinterpret_cast<Connector*>(cl.b)->execute();

    return 0;
}

void parse(const std::string &cmdLine, CommandLine &result) {
    std::istringstream iss(cmdLine);

    std::vector<std::string> buffer;
    std::string arg;
    Base* root;
    Connector* c;

    while (iss >> arg) {
        bool endOfCmd = false;
        c = nullptr;
    
        if (arg == "||") {
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

        if (endOfCmd) {
            // construct Command object
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

    result.b = root;
}
