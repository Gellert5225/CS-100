#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

//void thread();
std::vector<std::vector<std::string>> parse(std::string fileName);
void printVector(const std::vector<std::vector<std::string>>& vec);

int main (int argc, char** argv) {
    
    printVector(parse("./sample.txt"));

    return 0;
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
        printf("child process %d started at %s", getpid(), ctime(&when));
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

std::vector<std::vector<std::string>> parse(std::string fileName) {
    std::vector<std::vector<std::string>> result;
    std::ifstream infile(fileName);

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string arg;

        std::vector<std::string> cmds;
        while (iss >> arg) {
            bool endOfCmd = false;
            if (arg.back() == ';') {
                arg = arg.substr(0, arg.size() - 1);
                endOfCmd = true;
            }
            cmds.push_back(arg);
            if (endOfCmd || iss.eof()) {
                result.push_back(cmds);
                cmds.clear();
            }
        }
    }

    return result;
}

void printVector(const std::vector<std::vector<std::string>>& vec) {
    for (auto i = 0; i < vec.size(); i++) {
        std::cout << i + 1 << "th cmd: ";
        for (auto j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << " ";
        }
    }
}