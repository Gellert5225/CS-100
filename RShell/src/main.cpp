#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#include <sstream>
#include <iostream>
#include <vector>
#include "Base.hpp"
#include "CommandLine.hpp"
#include "Command.hpp"
#include "AndOrSemicolon.hpp"

void thread();
void parse(const std::string &cmdLine, CommandLine &result);

int main(int argc, char** argv) {
    std::string cmd = "echo hello;";
    CommandLine cl;
    parse(cmd, cl);

    std::cout << reinterpret_cast<Connector*>(cl.b)->getLeft()->toString();

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
        if (arg == "||") {

        } else if (arg == "&&") {

        } else {
            if (arg.back() == ';') {
                arg = arg.substr(0, arg.size() - 1);
                endOfCmd = true;
                c = new Semicolon();
            }
            buffer.push_back(arg);
        }

        if (endOfCmd) {
            // construct Command object
            Command *cmd = new Command();
            cmd->setArgs(buffer);

            if (root == nullptr) {
                if (c == nullptr) root = cmd;
                else {
                    root = c;
                    c->setLeft(cmd);
                }
            } else {
                Base* temp = root;
                c->setLeft(temp);
                reinterpret_cast<Connector*>(temp)->setRight(cmd);
                root = c;
            }

        }
        
    }

    result.b = root;
}

void thread() {
    int i, status;
    pid_t childId, endId;
    time_t when;

    if ((childId = fork()) == -1) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    } else if (childId == 0) { // child process
        time(&when);
        printf("child process %d started at    %s", getpid(), ctime(&when));

        char* args[] = {"ls", "-a", 0};
        printf("RETURN STATUS: %i\n", execvp(args[0], args));

        sleep(10);
        exit(EXIT_SUCCESS);
    } else { // parent process
        time(&when);
        printf("parent process %d started at %s", getpid(), ctime(&when));

        for (int i = 0; i < 15; i++) {
            endId = waitpid(childId, &status, WNOHANG|WUNTRACED);
            if (endId == -1) {
                perror("waitpid() error");
                exit(EXIT_FAILURE);
            } else if (endId == 0) {
                time(&when);
                printf("parent waiting for child %d at %s", childId, ctime(&when));
                sleep(1);
            } else if (endId == childId) {
                if (WIFEXITED(status)) {
                    printf("child ended normally\n");
                } else if (WIFSIGNALED(status)) {
                    printf("child ended because of an uncaught signal\n");
                } else if (WIFSTOPPED(status)) {
                    printf("child process has stopped\n");
                } 
                exit(EXIT_SUCCESS);
                
            }
        }
    }
} 
