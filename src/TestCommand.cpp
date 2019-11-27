#include "TestCommand.hpp"
#include <sys/stat.h>

TestCommand::TestCommand(int size) 
: CommandBase(size) {}

bool TestCommand::execute() {
    struct stat buf;
    return (stat(args[1], &buf) == 0);
}