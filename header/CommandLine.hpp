#ifndef __COMMANDLINE_HPP__
#define __COMMANDLINE_HPP__

#include "Base.hpp"
#include "Connector.hpp"
#include <vector>

class CommandLine : public Base {
public:
    CommandLine();
    ~CommandLine();

    bool execute();
    std::string toString();

    Base* b;
};

#endif