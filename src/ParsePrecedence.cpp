#include "ParsePrecedence.hpp"
#include <vector>
#include <string>
#include <sstream>

#include "Command.hpp"

ParsePrecedence::ParsePrecedence(): ParseFactory() {}

Base* ParsePrecedence::parse(std::string& line) {
    std::istringstream iss(line);
    std::string temp;
    std::vector<std::string> buffer;

    while (iss >> temp) {
        buffer.push_back(temp);
    }
    
    std::vector<std::string> *cp = new std::vector<std::string>();
    *cp = buffer;
    Command* tc = new Command(buffer.size());
    tc->populate(cp);

    //tc->execute();

    return tc;
}