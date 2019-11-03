#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Base.hpp"

class Command : public Base {
public:
    Command();
    ~Command();

    virtual void execute();
};

#endif