#include "ParseTestCommand.hpp"
#include "TestCommand.hpp"
#include <vector>
#include <string>
#include <sstream>

ParseTestCommand::ParseTestCommand(): ParseFactory() {}

Base* ParseTestCommand::parse(std::string& line) {
    std::istringstream iss(line);
    std::string temp;
    std::vector<std::string>* buffer = new std::vector<std::string>();

    while (iss >> temp) {
        buffer->push_back(temp);
    }
    
    TestCommand* tc = new TestCommand(buffer->size());
    tc->populate(buffer);

    return tc;
}