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
    std::string getOutput();

    void setInput(char*);
    void setOutput(char*);
};

#endif