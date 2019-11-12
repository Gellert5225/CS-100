#include "../includes/Connector.hpp"

Connector::Connector() {}

Connector::~Connector() {}

void Connector::setLeft(Base* b) {
    left = b;
}

void Connector::setRight(Base* b) {
    right = b;
}

Base* Connector::getLeft() {
    return left;
}
Base* Connector::getRight() {
    return right;
}