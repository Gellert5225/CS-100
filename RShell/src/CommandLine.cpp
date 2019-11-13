#include "CommandLine.hpp"

CommandLine::CommandLine() {}
CommandLine::~CommandLine() {}

CommandLine::CommandLine(std::string& input) {
    
}


std::vector<Base*> CommandLine::getCommands() const {
    return {};
}

bool CommandLine::execute() {
    return false;
}
std::string CommandLine::toString() {
    return "";
}