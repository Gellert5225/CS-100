#include "gtest/gtest.h"
#include "input_redirect_test.hpp"
#include "output_redirect_test.hpp"
#include "pipe_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}