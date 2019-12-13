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
    char* getOutput();
    std::string getOutputStr();

    void setInput(char*);
    void setOutput(char*);
};

#endif