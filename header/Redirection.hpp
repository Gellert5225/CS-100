#ifndef __REDIRECTION_HPP__
#define __REDIRECTION_HPP__

#include "Connector.hpp"

class Redirection: public Connector {
public: 
    Redirection(): Connector() {}
    ~Redirection() {}

    virtual bool execute() = 0;
    virtual std::string toString() = 0;

    virtual char* getInput() = 0;
    virtual char* getOutput() = 0;
    virtual std::string getOutputStr() = 0;

    virtual void setInput(char*) = 0;
    virtual void setOutput(char*) = 0;

protected:
    char* input;
    char* output;
    std::string outString;
};

#endif