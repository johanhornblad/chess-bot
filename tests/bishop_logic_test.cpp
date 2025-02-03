#include <gtest/gtest.h>
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"

class BishopLogicTest : public ::testing::Test {
protected:

    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};

    void SetUp() override {
        // Code for setting up before each test
    }

    void TearDown() override {
        // Code for cleaning up after each test
    }

    // Add any necessary member variables or helper functions here
};

TEST_F(BishopLogicTest, moveRightForward) {
    
    // Example test case
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}