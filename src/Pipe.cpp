#include "Pipe.hpp"
#include "helper.hpp"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>

Pipe::Pipe()
:Connector() {
    output = "";
}

Pipe::~Pipe() {
}

bool Pipe::execute() {
    char* inbuf;
    int pipe_fd[2], pid, status, endId;

    if (pipe(pipe_fd) < 0) {
        perror("pipe");
        return false;
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) > 0) { 
        close(pipe_fd[0]);
        write(pipe_fd[1], right->toString().c_str(), strlen(right->toString().c_str())); 

        close(pipe_fd[1]); 

        read(pipe_fd[0], inbuf, strlen(right->toString().c_str()));
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
        close(pipe_fd[1]); 
        dup2(pipe_fd[0], 0);
        dup2(pipe_fd[1], 1);

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

std::string Pipe::toString() {
    return "|";
}