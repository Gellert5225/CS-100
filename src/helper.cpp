#include "helper.hpp"
#include <sstream>

std::vector<std::string> convert(Base* b) {
    std::string s = b->toString();
    std::istringstream iss(s);
    std::string temp;
    std::vector<std::string> v;
    while (iss >> temp) {
        v.push_back(temp);
    }

    return v;
}