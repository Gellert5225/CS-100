#include "ParsePrecedence.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <chrono>
#include <thread>

#include "Command.hpp"
#include "CommandLine.hpp"
#include "Connector.hpp"
#include "AndOrSemicolon.hpp"

ParsePrecedence::ParsePrecedence(): ParseFactory() {}

Base* ParsePrecedence::parse(std::string& line) {
    if (line.front() != '(') {
        line = ("(" + line + ")");
    }
    std::istringstream iss(line);
    std::string temp;
    std::vector<std::string> buffer;
    std::stack<Base*> rootStack;
    std::vector<std::string> connectors{"&&", "||", ";"};

    Base* root = nullptr;
    Base* current = nullptr;
    Connector* connector = nullptr;
    Semicolon* tempNode = new Semicolon();

    bool no_read = false;

    while (no_read || iss >> temp) {
        no_read = false;
        if (temp.front() == '(') {
            temp = temp.substr(1, temp.size() - 1);
            while (temp.back() != ')' && temp.back() != ';' && temp != "&&" && temp != "||") {
                if (temp.back() == ';') {
                    temp = temp.substr(0, temp.size() - 1);
                    connector = new Semicolon();
                }
                buffer.push_back(temp);
                iss >> temp;
            }
            if (temp.back() == ')') temp = temp.substr(0, temp.size() - 1);
            if (temp == "&&" || temp == "||") no_read = true;
            buffer.push_back(temp);
            std::vector<std::string> *cp = new std::vector<std::string>();
            *cp = buffer;
            Command* c = new Command(buffer.size());
            c->populate(cp);
            if (root == nullptr) root = c;
            tempNode->setLeft(c);
            current = c;
            if (connector != nullptr) rootStack.push(connector);
        } else if (temp == "&&") {
            if (connector == nullptr) {
                connector = new And();
                root = connector;
            } else {
                connector = new And();
            }
            if (root == current) {
                root = connector;
            }
            connector->setLeft(reinterpret_cast<Connector*>(current));
            tempNode = new Semicolon();
            connector->setRight(tempNode);
            current = tempNode;
            if (rootStack.size() != 0) {
                reinterpret_cast<Connector*>(rootStack.top())->setRight(connector);
            }
            //if (reinterpret_cast<Connector*>(current)->getLeft() == nullptr) printf("nullptr\n");
            //else printf("not null, %s", reinterpret_cast<Connector*>(current)->getLeft()->toString().c_str());
        } else if (temp == "||") {
            if (connector == nullptr) {
                connector = new Or();
                root = connector;
            } else {
                connector = new Or();
            }
            if (root == current) {
                root = connector;
            }
            connector->setLeft(reinterpret_cast<Connector*>(current));
            tempNode = new Semicolon();
            connector->setRight(tempNode);
            current = tempNode;
            if (rootStack.size() != 0) {
                reinterpret_cast<Connector*>(rootStack.top())->setRight(connector);
            }
        } else if (temp.back() == ')') {
            if (rootStack.size() != 0) {
                current = rootStack.top();
                rootStack.pop();
            }
        } else {
            if (temp.back() == ';') {
                temp = temp.substr(0, temp.size() - 1);
                connector = new Semicolon();
            } else {
                while (temp.back() != ')' && temp.back() != ';' && temp != "&&" && temp != "||") {
                    buffer.push_back(temp);
                    iss >> temp;
                }
                if (temp.back() == ')') temp = temp.substr(0, temp.size() - 1);
                if (temp == "&&" || temp == "||") no_read = true;
            }
            buffer.push_back(temp);
            std::vector<std::string> *cp = new std::vector<std::string>();
            *cp = buffer;
            Command* c = new Command(buffer.size());
            c->populate(cp);
            connector->setRight(c);
        }
        buffer.clear();
    }
    return root;
}