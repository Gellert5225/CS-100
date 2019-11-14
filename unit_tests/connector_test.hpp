#include "gtest/gtest.h"
#include "AndOrSemicolon.hpp"

TEST(ConnectorTestSet, AndTest_1) {
    And* a = new And();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("ls");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("echo");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), true);
}

TEST(ConnectorTestSet, AndTest_2) {
    And* a = new And();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("ls");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("ech");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), false);
}

TEST(ConnectorTestSet, OrTest_1) {
    Or* a = new Or();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("ls");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("echo");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), true);
}

TEST(ConnectorTestSet, OrTest_2) {
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

    EXPECT_EQ(a->execute(), true);
}

TEST(ConnectorTestSet, OrTest_3) {
    Or* a = new Or();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("lss");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("eco");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), false);
}

TEST(ConnectorTestSet, SemicolonTest_1) {
    Semicolon* a = new Semicolon();
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

    EXPECT_EQ(a->execute(), true);
}

TEST(ConnectorTestSet, SemicolonTest_2) {
    Semicolon* a = new Semicolon();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("lss");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("eco");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), false);
}

TEST(ConnectorTestSet, SemicolonTest_3) {
    Semicolon* a = new Semicolon();
    Command* left = new Command(2);
    std::vector<std::string>* v1 = new std::vector<std::string>();
    v1->push_back("ls");
    v1->push_back("-a");

    left->populate(v1);

    Command* right = new Command(2);
    std::vector<std::string>* v2 = new std::vector<std::string>();
    v2->push_back("eco");
    v2->push_back("hello");

    right->populate(v2);

    a->setLeft(left);
    a->setRight(right);

    EXPECT_EQ(a->execute(), false);
}