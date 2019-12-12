#ifndef __PIPE_HPP__
#define __PIPE_HPP__

#include "Connector.hpp"
#include "Command.hpp"

class Pipe : public Connector {
public:
    Pipe();
    ~Pipe();

    bool execute();
    std::string toString();

    const char* output;
};

#endif