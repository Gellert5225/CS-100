#include "gtest/gtest.h"
#include "OutputRedirect.hpp"
#include "InputRedirect.hpp"
#include "Command.hpp"
#include "ParsePrecedence.hpp"
#include "Pipe.hpp"

Pipe* setupPipe(std::string s1, std::string s2, std::string s3) {
    ParsePrecedence* p = new ParsePrecedence();
    Base* b1 = p->parse(s1);
    Base* b2 = p->parse(s2);
    Base* b3 = p->parse(s3);

    Pipe* pipe1 = new Pipe();
    Pipe* pipe2 = new Pipe();
    pipe1->setLeft(b1);
    pipe1->setRight(b2);
    pipe2->setLeft(pipe1);
    pipe2->setRight(b3);

    return pipe2;
}

TEST(PipeTestSet, execute) {
    EXPECT_EQ(setupPipe("ls", "tr a-z A-Z", "tee out.txt")->execute(), true);
}

TEST(PipeTestSet, execute_2) {
    EXPECT_EQ(setupPipe("lss", "tr a-z A-Z", "tee out.txt")->execute(), false);
}

TEST(PipeTestSet, execute_3) {
    EXPECT_EQ(setupPipe("ls", "tr a-z A-Z", "te out.txt")->execute(), false);
}