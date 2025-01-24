#include <gtest/gtest.h>
#include "../inc/player.h"

//Test class called PlayerTest
class PlayerTest : public ::testing::Test {
protected:
    


    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    // Class members declared here can be used by all tests in the test suite for PlayerTest.
};



// Sample test case
TEST_F(PlayerTest, TestConstructor) {
    Player player1 = Player{Color::WHITE};
    auto playerColor = player1.getPlayerColor();

    ASSERT_EQ(playerColor, Color::WHITE);
}

TEST_F(PlayerTest, ExistenceOfAPieceTableTest) {
     Player player1 = Player{Color::WHITE};
     auto pieces = player1.getPieces();
     ASSERT_TRUE(pieces.empty());

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}