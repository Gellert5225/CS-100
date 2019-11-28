#include "TestCommand.hpp"
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

TestCommand::TestCommand(int size) 
: CommandBase(size) {
}

bool TestCommand::execute() {
    struct stat buf;
    int status = stat(args[1], &buf);

    if (strcmp(args[0], "-e") == 0) {
        //printf("checking -e: %i\n", status);
        return status == 0;
    }
    if (strcmp(args[0], "-f") == 0) {
        //printf("checking -f\n");
        return S_ISREG(buf.st_mode);
    }
    if (strcmp(args[0], "-d") == 0) {
        return S_ISDIR(buf.st_mode);
    }

    return (stat(args[1], &buf) == 0);
}