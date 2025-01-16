#include <gtest/gtest.h>

// Sample function to be tested
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(BoardControllerTest, AddFunction) {
    EXPECT_EQ(add(1, 1), 2);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(-1, -1), -2);
    EXPECT_EQ(add(0, 0), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}