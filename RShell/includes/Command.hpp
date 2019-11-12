#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Base.hpp"
#include <vector>

class Command : public Base {
public:
    Command(int size);
    ~Command();

    void setArgs(const std::vector<std::string>* v);
    
    bool execute();
    virtual std::string toString();
private:
    int size;
    const char** args;
};

#endif