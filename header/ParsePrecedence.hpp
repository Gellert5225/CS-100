#ifndef __PARSE_PRECEDENCE_HPP__
#define __PARSE_PRECEDENCE_HPP__

#include "ParseFactory.hpp"

class ParsePrecedence : public ParseFactory {
public:
    ParsePrecedence();
    Base* parse(std::string&);
};

#endif