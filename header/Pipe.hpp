#ifndef __PIPE_HPP__
#define __PIPE_HPP__

#include "Redirection.hpp"
#include "Command.hpp"

class Pipe : public Redirection {
public:
    Pipe();
    ~Pipe();

    bool execute();
    std::string toString();

    char* getInput();
    std::string getOutput();

    void setInput(char*);
    void setOutput(char*);
};

#endif