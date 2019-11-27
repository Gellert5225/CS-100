#ifndef __PARSE_TEST_COMMAND_HPP__
#define __PARSE_TEST_COMMAND_HPP__

#include "ParseFactory.hpp"

class ParseTestCommand : public ParseFactory {
public:
    ParseTestCommand();
    Base* parse(std::string&);
};

#endif