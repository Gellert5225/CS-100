#ifndef __COMMAND_BASE_HPP__
#define __COMMAND_BASE_HPP__

#include "Base.hpp"
#include <vector>

class CommandBase : public Base {
public:
    CommandBase(int size);
    ~CommandBase();

    void populate(const std::vector<std::string>* v);
    
    virtual bool execute() = 0;
    std::string toString();
protected:
    int size;
    const char** args;
};

#endif