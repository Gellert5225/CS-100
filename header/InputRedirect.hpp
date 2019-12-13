#ifndef __INPUT_REDIRECT_HPP__
#define __INPUT_REDIRECT_HPP__

#include "Redirection.hpp"

class InputRedirect: public Redirection {
public:
    InputRedirect();
    ~InputRedirect();

    bool execute();
    std::string toString();

    char* getInput();
    char* getOutput();
    std::string getOutputStr();

    void setInput(char*);
    void setOutput(char*);
};

#endif