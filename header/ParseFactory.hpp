#ifndef __PARSE_HPP__
#define __PARSE_HPP__

#include "Base.hpp"

class ParseFactory {
public:
    ParseFactory();
    virtual Base* parse(std::string&) = 0;
};

#endif