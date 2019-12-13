#ifndef __OUTPUT_REDIRECT_HPP__
#define __OUTPUT_REDIRECT_HPP__

#include "Redirection.hpp"

class OutputRedirect: public Redirection {
public:
    OutputRedirect(bool);
    ~OutputRedirect();

    bool execute();
    std::string toString();

    char* getInput();
    char* getOutput();
    std::string getOutputStr();

    void setInput(char*);
    void setOutput(char*);
private: 
    bool append;
};

#endif