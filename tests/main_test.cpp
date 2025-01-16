#include <gtest/gtest.h>
class ChessBotTests : public ::testing::Test {
};

TEST_F(ChessBotTests, HelloWorldTest) {
    EXPECT_EQ(1 + 1, 2);
}

TEST_F(ChessBotTests, SampleTest) {
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}