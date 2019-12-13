#include "Pipe.hpp"
#include "helper.hpp"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>

Pipe::Pipe()
:Redirection() {
    if (dynamic_cast<Redirection*>(left) != nullptr) {
        input = strdup(dynamic_cast<Redirection*>(left)->getOutput());
    } else {
        input = new char[2];
    }
}

Pipe::~Pipe() {
    delete [] input;
    input = nullptr;
}

bool Pipe::execute() {
    if (!left->execute()) return false;
    if (dynamic_cast<Redirection*>(left) == nullptr) input = strdup(dynamic_cast<Command*>(left)->getOutputStr().c_str());
    else input = strdup(dynamic_cast<Redirection*>(left)->getOutputStr().c_str());
    
    char inbuf[1024];
    int pipe_fd[2], pipe_fd_1[2], pid, status, endId;

    if (pipe(pipe_fd) < 0) {
        perror("pipe");
        return false;
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe_fd_1) < 0) {
        perror("pipe");
        return false;
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) > 0) { 
        close(pipe_fd[0]); 
        close(pipe_fd_1[1]); 

        //printf("input is %s\n", input);
        write(pipe_fd[1], input, strlen(input));
        close(pipe_fd[1]);

        int size = read(pipe_fd_1[0], inbuf, sizeof(inbuf));

        char actual[size + 1];
        strcpy(actual, inbuf);
        actual[size] = '\0';
        //printf("inbuf is %s\n", actual);
        output = actual;
        outString.assign(actual, size);

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
        close(pipe_fd_1[0]);
        dup2(pipe_fd[0], 0);
        if (parent != nullptr) dup2(pipe_fd_1[1], 1);
        close(pipe_fd[0]);
        close(pipe_fd_1[1]);

        std::vector<std::string> v = convert(right);
        //printf("right is %s\n", right->toString().c_str());
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
    return left->toString() + " | " + right->toString();
}

char* Pipe::getInput() {
    return input;
}
char* Pipe::getOutput() {
    return output;
}

void Pipe::setInput(char* c) {
    input = c;
}
void Pipe::setOutput(char* c) {
    output = c;
}

std::string Pipe::getOutputStr() {
    return outString;
}