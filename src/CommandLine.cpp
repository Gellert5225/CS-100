#include "CommandLine.hpp"

bool IsType(const Base* src);

CommandLine::CommandLine():Base() {
    b = nullptr;
}
CommandLine::~CommandLine() {}

bool CommandLine::execute() {
    return b->execute();
}
std::string CommandLine::toString() {
    if (IsType(b)) {
        return reinterpret_cast<Connector*>(b)->getLeft()->toString() + " " +
            b->toString() + " " +
            reinterpret_cast<Connector*>(b)->getRight()->toString();
    }
    return b->toString();
}

bool IsType(const Base* src) {
  return dynamic_cast<const Connector*>(src) != nullptr;
}