#include "gtest/gtest.h"
#include "OutputRedirect.hpp"
#include "InputRedirect.hpp"
#include "Command.hpp"
#include "ParsePrecedence.hpp"

Base* setupOutput(std::string s1, std::string s2, std::string s3) {
    ParsePrecedence* p = new ParsePrecedence();
    Base* b1 = p->parse(s1);
    Base* b2 = p->parse(s2);
    Base* b3 = p->parse(s3);

    InputRedirect* in = new InputRedirect();
    OutputRedirect* out = new OutputRedirect(false);
    in->setLeft(b1);
    in->setRight(b2);
    out->setLeft(in);
    out->setRight(b3);

    return out;
}

TEST(OutputRedirectTestSet, execute) {
    EXPECT_EQ(setupOutput("cat", "names.txt", "out.txt")->execute(), true);
}

TEST(OutputRedirectTestSet, execute_2) {
    EXPECT_EQ(setupOutput("cat", "name.txt", "out.txt")->execute(), false);
}

TEST(OutputRedirectTestSet, execute_3) {
    EXPECT_EQ(setupOutput("ca", "names.txt", "out.txt")->execute(), false);
}