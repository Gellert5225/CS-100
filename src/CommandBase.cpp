#include "CommandBase.hpp"

CommandBase::CommandBase(int size) {
    this->size = size;
    args = new const char*[size + 1];
}

CommandBase::~CommandBase() {
    for (int i = 0; i < size; i++) {
        delete[] args[i];
        args[i] = nullptr;
    }
}

void CommandBase::populate(const std::vector<std::string>* v) {
    for (int i = 0; i < v->size(); i++) {
        this->args[i] = (*v)[i].c_str();
    }

    this->args[v->size()] = 0;
}

std::string CommandBase::toString() {
    std::string result;
    for (int i = 0; i < size; i++) {
        std::string str(this->args[i]);
        result += str;
        result += " ";
    }
    result.pop_back();
    return result;
}