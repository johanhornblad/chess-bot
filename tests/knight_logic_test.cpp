#include <gtest/gtest.h>
#include "../inc/knight_logic.h"
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"
#include "../inc/move.h"

class KnightLogicTest : public ::testing::Test {
protected:

    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};
    void SetUp() override {
        // Code for setting up before each test
    }

    void TearDown() override {
        // Code for cleaning up after each test
    }
};

TEST_F(KnightLogicTest, KnightCanMoveVerticallyWhite) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 2 && move.endColumn == startCol + 1) {
            moveCount++;
        }
        if(move.endRow == startRow + 2 && move.endColumn == startCol - 1) {
            moveCount++;
        }
        if(move.endRow == startRow - 2 && move.endColumn == startCol + 1) {
            moveCount++;
        }
        if(move.endRow == startRow - 2 && move.endColumn == startCol - 1) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 4);

}

TEST_F(KnightLogicTest, KnightCanMoveVerticallyBlack) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 2 && move.endColumn == startCol + 1) {
            moveCount++;
        }
        if(move.endRow == startRow + 2 && move.endColumn == startCol - 1) {
            moveCount++;
        }
        if(move.endRow == startRow - 2 && move.endColumn == startCol + 1) {
            moveCount++;
        }
        if(move.endRow == startRow - 2 && move.endColumn == startCol - 1) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 4);

}
TEST_F(KnightLogicTest, KnightCanMoveHorizonallyWhite) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 1 && move.endColumn == startCol + 2) {
            moveCount++;
        }
        if(move.endRow == startRow - 1 && move.endColumn == startCol + 2) {
            moveCount++;
        }
        if(move.endRow == startRow + 1 && move.endColumn == startCol - 2) {
            moveCount++;
        }
        if(move.endRow == startRow - 1 && move.endColumn == startCol - 2) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 4);

}

TEST_F(KnightLogicTest, KnightCanMoveHorizonallyBlack) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 1 && move.endColumn == startCol + 2) {
            moveCount++;
        }
        if(move.endRow == startRow - 1 && move.endColumn == startCol + 2) {
            moveCount++;
        }
        if(move.endRow == startRow + 1 && move.endColumn == startCol - 2) {
            moveCount++;
        }
        if(move.endRow == startRow - 1 && move.endColumn == startCol - 2) {
            moveCount++;
        }
    }

    ASSERT_EQ(moveCount, 4);

}


TEST_F(KnightLogicTest, KnightCannotMoveToABlockedSquareWhite) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    board[startRow + 2][startCol + 1] = Square{Piece::PAWN, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        ASSERT_FALSE(move.endRow == startRow + 2 && move.endColumn == startCol + 1);
        moveCount++;
    }

    ASSERT_EQ(moveCount, 7);

}


TEST_F(KnightLogicTest, KnightCannotMoveToABlockedSquareBlack) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    board[startRow + 2][startCol + 1] = Square{Piece::PAWN, color};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        ASSERT_FALSE(move.endRow == startRow + 2 && move.endColumn == startCol + 1);
        moveCount++;
    }

    ASSERT_EQ(moveCount, 7);

}



TEST_F(KnightLogicTest, KnightCanTakeAsWhite) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::WHITE;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    board[startRow + 2][startCol + 1] = Square{Piece::PAWN, Color::BLACK};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);
    
    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 2 && move.endColumn == startCol + 1) {
            ASSERT_EQ(move.capture, Piece::PAWN);
        }
        moveCount++;
    }

    ASSERT_EQ(moveCount, 8);

}

TEST_F(KnightLogicTest, KnightCanTakeAsBlack) {
    auto factory = PieceLogicFactory{};
    auto knightLogic = factory.getPieceLogic(Piece::KNIGHT);
    auto startRow = 3;
    auto startCol = 3;
    auto color = Color::BLACK;
    board[startRow][startCol] = Square{Piece::KNIGHT, color};
    board[startRow + 2][startCol + 1] = Square{Piece::PAWN, Color::WHITE};
    auto moves = knightLogic->getAvaiableMoves(startRow, startCol, color, board);

    auto moveCount = 0;
    for(const auto& move : moves) {
        if(move.endRow == startRow + 2 && move.endColumn == startCol + 1) {
            ASSERT_EQ(move.capture, Piece::PAWN);
        }
        moveCount++;
    }

    ASSERT_EQ(moveCount, 8);

}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}