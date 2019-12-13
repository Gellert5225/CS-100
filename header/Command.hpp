#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Base.hpp"
#include <vector>

class Command : public Base {
public:
    Command(int size);
    ~Command();

    void populate(const std::vector<std::string>* v);
    
    bool execute();
    virtual std::string toString();
    
    char* getOutput();
private:
    int size;
    const char** args;
    char* output;
};

#endif