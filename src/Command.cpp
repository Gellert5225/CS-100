#include "Command.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include <iostream>

Command::Command(int size): Base() {
    this->size = size;
    args = new const char*[size + 1];
}

Command::~Command() {
    for (int i = 0; i < size; i++) {
        delete[] args[i];
        args[i] = nullptr;
    }
}

void Command::populate(const std::vector<std::string>* v) {
    for (int i = 0; i < v->size(); i++) {
        this->args[i] = (*v)[i].c_str();
    }

    this->args[v->size()] = 0;
}

bool Command::execute() {
    int i, status;
    pid_t childId, endId;
    time_t when;

    if (strcmp(args[0], "exit") == 0) exit(EXIT_SUCCESS);

    if ((childId = fork()) == -1) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    } else if (childId == 0) { // child process
        time(&when);
        //printf("child process %d started at    %s", getpid(), ctime(&when));

        if (execvp(args[0], (char* const*)args) < 0) {
            printf("Error executing command \"%s\", %s\n", this->toString().c_str(), strerror(errno));
            exit(errno);
        }
        //exit(EXIT_SUCCESS);
    } else { // parent process
        time(&when);
        //printf("parent process %d started at %s", getpid(), ctime(&when));
        endId = waitpid(childId, &status, 0);
        if (endId == -1) {
            perror("waitpid() error");
            exit(EXIT_FAILURE);
        } else if (endId == 0) {
            time(&when);
            //printf("parent waiting for child %d at %s", childId, ctime(&when));
        } else if (endId == childId) {
            if (WIFEXITED(status)) {
                //printf("child ended with %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("child ended because of an uncaught signal\n");
            } else if (WIFSTOPPED(status)) {
                printf("child process has stopped\n");
            } 
            kill(childId, SIGKILL);
        }
    } 
    return WEXITSTATUS(status) == 0;
}

std::string Command::toString() {
    std::string result;
    for (int i = 0; i < size; i++) {
        std::string str(this->args[i]);
        result += str;
        result += " ";
    }
    result.pop_back();
    return result;
}