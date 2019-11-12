#include "../includes/AndOrSemicolon.hpp"

Semicolon::Semicolon(): Connector() {}
Semicolon::~Semicolon() {}

bool Semicolon::execute() {
    return false;
}
std::string Semicolon::toString() {
    return ";";
}