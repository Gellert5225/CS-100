#include "gtest/gtest.h"
#include "Command.hpp"

TEST(CommandTestSet, toStringTest) {
    Command* cmd = new Command(2);
    std::vector<std::string>* v = new std::vector<std::string>();
    v->push_back("ls");
    v->push_back("-a");

    cmd->populate(v);
    EXPECT_EQ(cmd->toString(), "ls -a");
}

TEST(CommandTestSet, executeTest) {
    Command* cmd = new Command(2);
    std::vector<std::string>* v = new std::vector<std::string>();
    v->push_back("ls");
    v->push_back("-a");

    cmd->populate(v);
    EXPECT_EQ(cmd->execute(), true);
}

TEST(CommandTestSet, executeTest2) {
    Command* cmd = new Command(2);
    std::vector<std::string>* v = new std::vector<std::string>();
    v->push_back("ls");
    v->push_back("k");

    cmd->populate(v);
    EXPECT_EQ(cmd->execute(), false);
}