#ifndef __TEST_COMMAND_HPP__
#define __TEST_COMMAND_HPP__

#include "CommandBase.hpp"

class TestCommand : public CommandBase {
public:
    TestCommand(int size);

    bool execute();

};

#endif