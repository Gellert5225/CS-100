#include "CommandLine.hpp"

CommandLine::CommandLine():Base() {
    b = nullptr;
}
CommandLine::~CommandLine() {}

bool CommandLine::execute() {
    return b->execute();
}
std::string CommandLine::toString() {
    return b->toString();
}