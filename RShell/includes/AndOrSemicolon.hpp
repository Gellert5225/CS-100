#ifndef __ANDORSEMICOLON_HPP__
#define __ANDORSEMICOLON_HPP__

#include "Connector.hpp"

class And : public Connector {
public:
    And();
    ~And();

    bool execute();
    std::string toString();
};

class Or : public Connector {
public:
    Or();
    ~Or();

    bool execute();
    std::string toString();
};

class Semicolon : public Connector {
public:
    Semicolon();
    ~Semicolon();

    bool execute();
    std::string toString();
};

#endif