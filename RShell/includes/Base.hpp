#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
public:
    Base() {}
    ~Base() {}

    virtual void execute() = 0;
    virtual std::string toString() = 0;
    virtual bool run() = 0;
};

#endif
