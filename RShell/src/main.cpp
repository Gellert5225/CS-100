#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork() error, exiting program.");
        exit(-1);
    } 
    if (pid > 0) {
        printf("I am parent %d, my child is %d\n", getpid(), pid);
        wait(NULL);
    } else {
        printf("I am child %d, my parent is %d\n", getpid(), getppid());

        printf("-----------------");

        char* args[] = {"ls", "-a", 0};
        execvp(args[0], args);
    }

    return 0;
}
