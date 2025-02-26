#include <gtest/gtest.h>
#include "../inc/king_logic.h"
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"
#include "../inc/move.h"


class KingLogicTest : public ::testing::Test {
protected:
    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    // Class members and helper functions can be declared here.
};

// Example test case
TEST_F(KingLogicTest, KingCanMoveOneSquareInAnyDirectionAsWhite) {
    auto factory = PieceLogicFactory{};
    auto kingLogic = factory.getPieceLogic(Piece::KING);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KING, color};
    auto moves = kingLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    std::vector<std::pair<int, int>> expectedMoves = {
        {startRow + 1, startCol}, {startRow - 1, startCol}, {startRow, startCol + 1}, {startRow, startCol - 1},
        {startRow + 1, startCol + 1}, {startRow + 1, startCol - 1}, {startRow - 1, startCol + 1}, {startRow - 1, startCol - 1}
    };

    int moveCount = 0;
    for(const auto& move : moves) {
        for(const auto& expectedMove : expectedMoves) {
            if(move.endRow == expectedMove.first && move.endColumn == expectedMove.second) {
                moveCount++;
            }
        }
    }

    ASSERT_EQ(moveCount, 8);
}


// Example test case
TEST_F(KingLogicTest, KingCanMoveOneSquareInAnyDirectionAsBlack) {
    auto factory = PieceLogicFactory{};
    auto kingLogic = factory.getPieceLogic(Piece::KING);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KING, color};
    auto moves = kingLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    std::vector<std::pair<int, int>> expectedMoves = {
        {startRow + 1, startCol}, {startRow - 1, startCol}, {startRow, startCol + 1}, {startRow, startCol - 1},
        {startRow + 1, startCol + 1}, {startRow + 1, startCol - 1}, {startRow - 1, startCol + 1}, {startRow - 1, startCol - 1}
    };

    int moveCount = 0;
    for(const auto& move : moves) {
        for(const auto& expectedMove : expectedMoves) {
            if(move.endRow == expectedMove.first && move.endColumn == expectedMove.second) {
                moveCount++;
            }
        }
    }

    ASSERT_EQ(moveCount, 8);
}

TEST_F(KingLogicTest, KingCannotMoveIfBlockedAsWhite) {
    auto factory = PieceLogicFactory{};
    auto kingLogic = factory.getPieceLogic(Piece::KING);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KING, color};
    board[startRow + 1][startCol] = Square{Piece::PAWN, color};
    board[startRow - 1][startCol] = Square{Piece::PAWN, color};
    board[startRow][startCol + 1] = Square{Piece::PAWN, color};
    board[startRow][startCol - 1] = Square{Piece::PAWN, color};
    board[startRow + 1][startCol + 1] = Square{Piece::ROOK, color};
    board[startRow + 1][startCol - 1] = Square{Piece::ROOK, color};
    board[startRow - 1][startCol + 1] = Square{Piece::BISHOP, color};
    board[startRow - 1][startCol - 1] = Square{Piece::BISHOP, color};
    
    auto moves = kingLogic->getAvaiableMoves(startRow, startCol, color, board);

    int moveCount = static_cast<int>(moves.size());

    ASSERT_EQ(moveCount, 0);
}

TEST_F(KingLogicTest, KingCannotMoveIfBlockedAsBlack) {
    auto factory = PieceLogicFactory{};
    auto kingLogic = factory.getPieceLogic(Piece::KING);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KING, color};
    board[startRow + 1][startCol] = Square{Piece::PAWN, color};
    board[startRow - 1][startCol] = Square{Piece::PAWN, color};
    board[startRow][startCol + 1] = Square{Piece::PAWN, color};
    board[startRow][startCol - 1] = Square{Piece::PAWN, color};
    board[startRow + 1][startCol + 1] = Square{Piece::ROOK, color};
    board[startRow + 1][startCol - 1] = Square{Piece::ROOK, color};
    board[startRow - 1][startCol + 1] = Square{Piece::BISHOP, color};
    board[startRow - 1][startCol - 1] = Square{Piece::BISHOP, color};
    
    auto moves = kingLogic->getAvaiableMoves(startRow, startCol, color, board);

    int moveCount = static_cast<int>(moves.size());

    ASSERT_EQ(moveCount, 0);
}

TEST_F(KingLogicTest, KingCanCaptureAsWhite) {
    auto factory = PieceLogicFactory{};
    auto kingLogic = factory.getPieceLogic(Piece::KING);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KING, color};
    board[startRow + 1][startCol] = Square{Piece::PAWN, Color::BLACK};
    board[startRow - 1][startCol] = Square{Piece::PAWN, Color::BLACK};
    board[startRow][startCol + 1] = Square{Piece::PAWN, Color::BLACK};
    board[startRow][startCol - 1] = Square{Piece::PAWN, Color::BLACK};
    board[startRow + 1][startCol + 1] = Square{Piece::ROOK, Color::BLACK};
    board[startRow + 1][startCol - 1] = Square{Piece::ROOK, Color::BLACK};
    board[startRow - 1][startCol + 1] = Square{Piece::BISHOP, Color::BLACK};
    board[startRow - 1][startCol - 1] = Square{Piece::BISHOP, Color::BLACK};

    auto moves = kingLogic->getAvaiableMoves(startRow, startCol, color, board);
    

    int moveCount = 0;
    for(const auto& move : moves) {
      ASSERT_NE(move.capture, Piece::EMPTY);
      moveCount++;
    }

    ASSERT_EQ(moveCount, 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}