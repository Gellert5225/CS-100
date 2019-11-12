#include "../includes/AndOrSemicolon.hpp"

// Semicolon
Semicolon::Semicolon(): Connector() {}
Semicolon::~Semicolon() {}

bool Semicolon::execute() {
    left->execute();
    return right->execute();
}
std::string Semicolon::toString() {
    return ";";
}

// And
And::And() {}
And::~And() {}

bool And::execute() {
    return left->execute() && right->execute();
}

std::string And::toString() {
    return "&&";
}

// Or
Or::Or() {}
Or::~Or() {}

bool Or::execute() {
    return left->execute() || right->execute();
}

std::string Or::toString() { 
    return "||"; 
}