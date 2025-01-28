#include <gtest/gtest.h>
#include "../inc/pawn_logic.h"
#include "../inc/piece_logic_factory.h"
#include "../inc/board_controller.h"


class PawnLogicTest : public ::testing::Test {
protected:
    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};



    
    void SetUp() override {
        boardController.initialSetup(board);
        // Code for setting up before each test
    }

    void TearDown() override {
        // Code for cleaning up after each test
    }
};


TEST_F(PawnLogicTest, MoveOneForwardAsWhite) {
     auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 4;
     auto startCol = 4;

    auto move1 = Move{startRow, startCol, startRow + 1, startCol, Piece::EMPTY, false, Piece::EMPTY};

    std::vector<Move> availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol,Color::WHITE, board);

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 1);
     EXPECT_EQ(availableMoves[0].endRow, startRow + 1);
     EXPECT_EQ(availableMoves[0].endColumn, startCol);
}

TEST_F(PawnLogicTest, CannotMoveIfSquareIsBlocked) {
     auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 4;
     auto startCol = 4;

    board[startRow + 1][ startCol] = Square{Piece::ROOK, Color::WHITE};
    auto move1 = Move{startRow, startCol, startRow + 1, startCol, Piece::EMPTY, false, Piece::EMPTY};

    std::vector<Move> availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol,Color::WHITE, board);

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 0);
}

TEST_F(PawnLogicTest, MoveOneForwardAsBlack) {
     auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 4;
     auto startCol = 4;

    auto move1 = Move{startRow, startCol, startRow + 1, startCol, Piece::EMPTY, false, Piece::EMPTY};

    std::vector<Move> availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol,Color::BLACK, board);

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 1);
     EXPECT_EQ(availableMoves[0].endRow, startRow - 1);
     EXPECT_EQ(availableMoves[0].endColumn, startCol);

}

// Example test case
TEST_F(PawnLogicTest, FromStartPositionGetTwoAvailableMovesAsWhite) {
     auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 1;
     auto startCol = 4;

    auto move1 = Move{startRow, startCol, startRow + 1, startCol, Piece::EMPTY, false, Piece::EMPTY};
    auto move2 = Move{startRow, startCol, startRow + 2, startCol, Piece::EMPTY, false, Piece::EMPTY};

    std::vector<Move> availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol,Color::WHITE, board);

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 2);
     EXPECT_EQ(availableMoves[0].endRow, startRow + 1);
     EXPECT_EQ(availableMoves[0].endColumn, startCol);
     EXPECT_EQ(availableMoves[1].endRow, startRow + 2);
     EXPECT_EQ(availableMoves[1].endColumn, startCol);

}

TEST_F(PawnLogicTest, FromStartPositionGetTwoAvailableMovesAsBlack) {
     auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 6;
     auto startCol = 4;

    std::vector<Move> availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol,Color::BLACK, board);

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 2);
     EXPECT_EQ(availableMoves[0].endRow, startRow - 1);
     EXPECT_EQ(availableMoves[0].endColumn, startCol);
     EXPECT_EQ(availableMoves[1].endRow, startRow - 2);
     EXPECT_EQ(availableMoves[1].endColumn, startCol);

}

TEST_F(PawnLogicTest, CanIdentifyACaptureAsWhite) {
 auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 1;
     auto startCol = 4;
     board[2][5] = Square{Piece::PAWN, Color::BLACK};

     auto availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
     bool isCaptured = false;
     
     for (const auto& move : availableMoves) {
        if(move.capture != Piece::EMPTY) {
            EXPECT_EQ(move.capture, Piece::PAWN);
            EXPECT_EQ(move.endRow, 2);
            EXPECT_EQ(move.endColumn, 5);
            isCaptured = true;
        }
     }

     EXPECT_TRUE(isCaptured);
}

TEST_F(PawnLogicTest, CanIdentifyACaptureAsBlack) {
 auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 6;
     auto startCol = 4;
     // set enemy piece
     board[5][5] = Square{Piece::PAWN, Color::WHITE};

     auto availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
     bool isCaptured = false;
     
     for (const auto& move : availableMoves) {
        if(move.capture != Piece::EMPTY) {
            EXPECT_EQ(move.capture, Piece::PAWN);
            EXPECT_EQ(move.endRow, 5);
            EXPECT_EQ(move.endColumn, 5);
            isCaptured = true;
        }
     }

     EXPECT_TRUE(isCaptured);
}


TEST_F(PawnLogicTest, CanMovePawnAgainstTheWall) {
 auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 1;
     auto startCol = 0;
     // set enemy piece
     board[2][1] = Square{Piece::PAWN, Color::BLACK};

     auto availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
     bool isCaptured = false;
     
     for (const auto& move : availableMoves) {
        if(move.capture != Piece::EMPTY) {
            EXPECT_EQ(move.capture, Piece::PAWN);
            isCaptured = true;
        }
     }

     EXPECT_EQ(static_cast<int>(availableMoves.size()), 3);
     EXPECT_TRUE(isCaptured);
}

TEST_F(PawnLogicTest, TestPawnPromotionAswhite) {
 auto factory = PieceLogicFactory{};
     auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
     auto startRow = 6;
     auto startCol = 4;

     auto availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    
     auto move = availableMoves[0];


     EXPECT_NE(move.promotionPiece, Piece::EMPTY);
     EXPECT_TRUE(move.isPawnPromotion);
}

TEST_F(PawnLogicTest, TestPawnPromotionAsBlack) {
 auto factory = PieceLogicFactory{};
    auto pawnLogic = factory.getPieceLogic(Piece::PAWN);
    auto startRow = 1;
    auto startCol = 4;
    auto availableMoves = pawnLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);

    auto move = availableMoves[0];


     EXPECT_NE(move.promotionPiece, Piece::EMPTY);
     EXPECT_TRUE(move.isPawnPromotion);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}