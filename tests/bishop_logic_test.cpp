#include <gtest/gtest.h>
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"
#include "../inc/bishop_logic.h"

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

TEST_F(BishopLogicTest, moveRightForwardWhite) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow > startRow && move.endColumn > startCol) {
            moveCount++;
            ASSERT_EQ(move.endRow, move.endColumn);
        }
    }

    ASSERT_EQ(moveCount, 3);
}

TEST_F(BishopLogicTest, moveRightForwardBlack) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow < startRow && move.endColumn < startCol) {
            moveCount++;
            ASSERT_EQ(move.endRow, move.endColumn);
        }
    }

    ASSERT_EQ(moveCount, 4);
}


TEST_F(BishopLogicTest, moveLeftForwardWhite) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow > startRow && move.endColumn < startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 3);
}

TEST_F(BishopLogicTest, moveLeftForwardBlack) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow < startRow && move.endColumn > startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 3);
}

TEST_F(BishopLogicTest, moveRightBackwardsWhite) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow < startRow && move.endColumn > startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 3);
}

TEST_F(BishopLogicTest, moveRightBackwardsBlack) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow > startRow && move.endColumn < startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 3);
}

TEST_F(BishopLogicTest, moveLeftBackwardsWhite) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow < startRow && move.endColumn < startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 4);
}

TEST_F(BishopLogicTest, moveLeftBackwardsBlack) {
    int startRow = 4;
    int startCol = 4;
    auto factory = PieceLogicFactory{};
    auto bishopLogic = factory.getPieceLogic(Piece::BISHOP);
    auto moves = bishopLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);

    int moveCount = 0;
    for (const auto& move : moves) {
        if(move.endRow > startRow && move.endColumn > startCol) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}