#ifndef __OUTPUT_REDIRECT_HPP__
#define __OUTPUT_REDIRECT_HPP__

#include "Redirection.hpp"

class OutputRedirect: public Redirection {
public:
    OutputRedirect();
    ~OutputRedirect();

    bool execute();
    std::string toString();

    char* getInput();
    char* getOutput();

    void setInput(char*);
    void setOutput(char*);
};

#endif