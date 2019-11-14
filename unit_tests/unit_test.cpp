#include "gtest/gtest.h"
#include "command_test.hpp"
#include "connector_test.hpp"
#include "command_line_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}