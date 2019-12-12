#ifndef __INPUT_REDIRECT_HPP__
#define __INPUT_REDIRECT_HPP__

#include "Connector.hpp"

class InputRedirect: public Connector {
public:
    InputRedirect();
    ~InputRedirect();

    bool execute();
    std::string toString();

    const char* output;
};

#endif