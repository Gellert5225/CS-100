#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
public:
    Base() { parent = nullptr; }
    ~Base() {}

    virtual bool execute() = 0;
    virtual std::string toString() = 0;
    Base* parent;
};

#endif
