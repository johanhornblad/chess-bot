#include <gtest/gtest.h>
#include "../inc/square.h"
#include "../inc/board_controller.h"

class BoardControllerTest : public ::testing::Test {
    public:
        std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
};

// Sample function to be tested

TEST_F(BoardControllerTest, SetWhitePawnOnStartPositions) {
 
    auto boardController = BoardController{};

    boardController.initialSetup(board);
    int i = 1;
    for(int j = 0; j < 8; j++) {
            auto tmpPawnPos = board[i][j];
            ASSERT_TRUE(tmpPawnPos.color == Color::WHITE);
            ASSERT_TRUE(tmpPawnPos.piece == Piece::PAWN);
    }
}

TEST_F(BoardControllerTest, SetBlackPawnOnStartPositions) {
 
    auto boardController = BoardController{};

    boardController.initialSetup(board);
    int i = 6;
    for(int j = 0; j < 8; j++) {
            auto tmpPawnPos = board[i][j];
            ASSERT_TRUE(tmpPawnPos.color == Color::BLACK);
            ASSERT_TRUE(tmpPawnPos.piece == Piece::PAWN);
    }
}

TEST_F(BoardControllerTest, WhitePawnsShouldNotExistsONNonPawnPosisions) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    for(int i = 0; i < 8; i++) {
        if(i == 1) continue;
        for(int j = 0; j < 8; j++) {
            auto sqaure = board[i][j];
            if(sqaure.color == Color::WHITE && sqaure.piece == Piece::PAWN) {
                std::cout << "ERROR: square board[" << i << "][" << j << "] has a pawn" << std::endl;
                ASSERT_NE(sqaure.piece, Piece::PAWN);
            }
        }

    }
}

TEST_F(BoardControllerTest, SetWhiteRookTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto rook = Square{Piece::ROOK, Color::WHITE};
    ASSERT_TRUE(board[0][0].piece == rook.piece && board[0][0].color == rook.color);
    ASSERT_TRUE(board[0][7].piece == rook.piece && board[0][7].color == rook.color);
}

TEST_F(BoardControllerTest, SetBlackRookTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto rook = Square{Piece::ROOK, Color::BLACK};
    ASSERT_TRUE(board[7][7].piece == rook.piece && board[7][7].color == rook.color);
    ASSERT_TRUE(board[7][0].piece == rook.piece && board[7][0].color == rook.color);
}


TEST_F(BoardControllerTest, SetWhiteKnightTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto knight = Square{Piece::KNIGHT, Color::WHITE};
    ASSERT_TRUE(board[7][7].piece == knight.piece && board[7][7].color == knight.color);
    ASSERT_TRUE(board[7][0].piece == knight.piece && board[7][0].color == knight.color);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}