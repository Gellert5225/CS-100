#include "../includes/AndOrSemicolon.hpp"
#include <iostream>

// Semicolon
Semicolon::Semicolon(): Connector() {}

Semicolon::~Semicolon() {}

bool Semicolon::execute() {
    if (left != nullptr) left->execute();
    if (right != nullptr) return right->execute();

    return false;
}
std::string Semicolon::toString() {
    return ";";
}

// And
And::And() {}
And::~And() {}

bool And::execute() {
    if (right != nullptr)
        return left->execute() && right->execute();
    if (!left->execute()) std::cerr << "missing argument after &&" << std::endl;
    return false;
}

std::string And::toString() {
    return "&&";
}

// Or
Or::Or() {}
Or::~Or() {}

bool Or::execute() {
    if (right != nullptr)
        return left->execute() || right->execute();
    std::cerr << "missing argument after ||" << std::endl;
    return false;
}

std::string Or::toString() { 
    return "||"; 
}