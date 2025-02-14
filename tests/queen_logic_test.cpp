#include <gtest/gtest.h>
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"
#include "../inc/queen_logic.h"  
#include "../inc/move.h"
#include <vector>

class QueenTest : public ::testing::Test {
protected:

    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for Queen.
  
};

// Test case to verify the queen's ability to move in all directions
TEST_F(QueenTest, QueenCanMoveStraight) {
    // Arrange
    QueenLogic queenLogic;
    int startRow = 3;
    int startColumn = 3;
    Color color = Color::WHITE;
    board[startRow][startColumn] = Square{Piece::QUEEN, color};

    // Act
    auto availableMoves = queenLogic.getAvaiableMoves(startRow, startColumn, color, board);

    // Assert
    int straightMoveCount = 0;
    for (const auto& move : availableMoves) {
        if((move.endRow > startRow|| move.endRow < startRow) && move.endColumn == startColumn) {
            straightMoveCount++;
        }
        if((move.endColumn > startColumn|| move.endColumn < startColumn) && move.endRow == startRow) {
            straightMoveCount++;
        }
    }

    ASSERT_EQ(straightMoveCount, 14);
}

TEST_F(QueenTest, QueenCanMoveDiagonally) {
    // Arrange
    QueenLogic queenLogic;
    int startRow = 3;
    int startColumn = 3;
    Color color = Color::WHITE;
    board[startRow][startColumn] = Square{Piece::QUEEN, color};

    // Act
    auto availableMoves = queenLogic.getAvaiableMoves(startRow, startColumn, color, board);

    // Assert
    int straightMoveCount = 0;
    for (const auto& move : availableMoves) {
        if((move.endRow > startRow && move.endColumn > startColumn) || (move.endRow < startRow && move.endColumn < startColumn)) {
            straightMoveCount++;
        }
        if((move.endRow > startRow && move.endColumn < startColumn) || (move.endRow < startRow && move.endColumn > startColumn)) {
            straightMoveCount++;
        }
    }

    ASSERT_EQ(straightMoveCount, 13);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
