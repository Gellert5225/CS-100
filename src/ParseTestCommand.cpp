#include "ParseTestCommand.hpp"
#include "TestCommand.hpp"
#include <vector>
#include <string>
#include <sstream>

ParseTestCommand::ParseTestCommand(): ParseFactory() {}

Base* ParseTestCommand::parse(std::string& line) {
    std::istringstream iss(line);
    std::string temp;
    std::vector<std::string> buffer;

    while (iss >> temp) {
        buffer.push_back(temp);
    }
    
    std::vector<std::string> *cp = new std::vector<std::string>();
    *cp = buffer;
    TestCommand* tc = new TestCommand(buffer.size());
    tc->populate(cp);

    tc->execute();

    return tc;
}