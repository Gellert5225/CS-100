#ifndef __COMMANDLINE_HPP__
#define __COMMANDLINE_HPP__

#include "Base.hpp"
#include <vector>

class CommandLine : public Base {
public:
    CommandLine();
    CommandLine(std::string&);
    ~CommandLine();

    std::vector<Base*> getCommands() const;
    void pushCommand(Base* c);

    bool execute();
    std::string toString();

    Base* b;
private:
    std::vector<Base*> commands;
};

#endif