#include "Command.hpp"

Command::Command() {}

Command::~Command() {}

void Command::setArgs(const std::vector<std::string>& v) {
    size = v.size();
    args = new const char*[v.size()];
    for (int i = 0; i < v.size(); i++)
        args[i] = v[i].c_str();
}

bool Command::execute() {
    return false;
}

std::string Command::toString() {
    std::string result;
    for (int i =0; i < size; i++) {
        result += args[i];
        result += " ";
    }
    return result;
}