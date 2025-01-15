#include <gtest/gtest.h>

TEST(HelloWorldTest, BasicAssertions) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(SampleTest, AssertionTrue) {
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}