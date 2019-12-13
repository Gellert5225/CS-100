#include "gtest/gtest.h"
#include "InputRedirect.hpp"
#include "Command.hpp"
#include "ParsePrecedence.hpp"

TEST(InputRedirectTestSet, execute) {
    std::string s1 = "cat";
    std::string s2 = "names.txt";
    ParsePrecedence* p = new ParsePrecedence();
    Base* b1 = p->parse(s1);
    Base* b2 = p->parse(s2);

    InputRedirect* in = new InputRedirect();
    in->setLeft(b1);
    in->setRight(b2);

    EXPECT_EQ(in->execute(), true);
}

TEST(InputRedirectTestSet, execute_2) {
    std::string s1 = "cat";
    std::string s2 = "wrong.txt";
    ParsePrecedence* p = new ParsePrecedence();
    Base* b1 = p->parse(s1);
    Base* b2 = p->parse(s2);

    InputRedirect* in = new InputRedirect();
    in->setLeft(b1);
    in->setRight(b2);

    EXPECT_EQ(in->execute(), false);
}

TEST(InputRedirectTestSet, execute_3) {
    std::string s1 = "ca";
    std::string s2 = "names.txt";
    ParsePrecedence* p = new ParsePrecedence();
    Base* b1 = p->parse(s1);
    Base* b2 = p->parse(s2);

    InputRedirect* in = new InputRedirect();
    in->setLeft(b1);
    in->setRight(b2);

    EXPECT_EQ(in->execute(), false);
}