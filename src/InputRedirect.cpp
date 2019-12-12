#include "InputRedirect.hpp"
#include "helper.hpp"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>
#include <vector>

InputRedirect::InputRedirect()
: Connector() {}

InputRedirect::~InputRedirect() {}

bool InputRedirect::execute() {
    int pid, status, endId;

    int in = open(right->toString().c_str(), O_RDONLY); 
    if (in < 0) { 
        printf("error opening"); 
        exit(-1); 
    }

    if ((pid = fork()) > 0) { 
        close(in); 

        endId = waitpid(pid, &status, 0);
        if (endId == -1) {
            perror("waitpid() error");
            exit(EXIT_FAILURE);
        } else if (endId == 0) {
            //printf("parent waiting for child %d at %s", childId, ctime(&when));
        } else if (endId == pid) {
            if (WIFEXITED(status)) {
                //printf("child ended with %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("child ended because of an uncaught signal\n");
            } else if (WIFSTOPPED(status)) {
                printf("child process has stopped\n");
            } 
            kill(pid, SIGKILL);
        }
    } else { 
        dup2(in, 0);
        std::vector<std::string> v = convert(left);
        char* cmd[v.size() + 1];
        for (int i = 0; i < v.size(); i++) {
            cmd[i] = const_cast<char*>(v.at(i).c_str());
        }

        cmd[v.size()] = 0;

        if (execvp(cmd[0], cmd) < 0) {
            printf("Error executing command, %s\n", strerror(errno));
            exit(errno);
        }
    } 

    return WEXITSTATUS(status) == 0;
}

std::string InputRedirect::toString() {
    return "<";
}

