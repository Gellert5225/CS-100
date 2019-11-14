#include "gtest/gtest.h"
#include "CommandLine.hpp"
#include "AndOrSemicolon.hpp"
#include "Command.hpp"

TEST(CLTestSet, toStringTest) {
    Or* a = new Or();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("lss");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("echo");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    CommandLine cl;
    cl.b = a;

    EXPECT_EQ(cl.toString(), "lss -a || echo hello");
}

TEST(CLTestSet, executeTest) {
    Or* a = new Or();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("lss");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("echo");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    CommandLine cl;
    cl.b = a;

    EXPECT_EQ(cl.execute(), true);
}