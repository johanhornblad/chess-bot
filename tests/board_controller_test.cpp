#include <gtest/gtest.h>
#include "../inc/square.h"
#include "../inc/board_controller.h"

class BoardControllerTest : public ::testing::Test {
    public:
        std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
};

TEST_F(BoardControllerTest, testPrintWithWhiteAsHumanPlayer) {
    
    auto boardController = BoardController{};
    boardController.printBoard(board, Color::WHITE);
}

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

TEST_F(BoardControllerTest, AllOtherSquaresONTheBoardIsEmptyTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    for(int i = 0; i < 8; i++) {
        
        for(int j = 0; j < 8; j++) {
            auto square = board[i][j];
            if(i == 0 || i == 1 || i == 6 || i == 7) {
                ASSERT_NE(board[i][j].piece, Piece::EMPTY);
            } else { 
                ASSERT_TRUE(square.color == Color::NONE && square.piece == Piece::EMPTY);
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
    ASSERT_TRUE(board[0][6].piece == knight.piece && board[0][6].color == knight.color);
    ASSERT_TRUE(board[0][1].piece == knight.piece && board[0][1].color == knight.color);
}

TEST_F(BoardControllerTest, SetBlackKnightTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto knight = Square{Piece::KNIGHT, Color::BLACK};
    ASSERT_TRUE(board[7][6].piece == knight.piece && board[7][6].color == knight.color);
    ASSERT_TRUE(board[7][1].piece == knight.piece && board[7][1].color == knight.color);
}


TEST_F(BoardControllerTest, SetWhiteBishopTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto bishop = Square{Piece::BISHOP, Color::WHITE};
    ASSERT_TRUE(board[0][5].piece == bishop.piece && board[0][5].color == bishop.color);
    ASSERT_TRUE(board[0][2].piece == bishop.piece && board[0][2].color == bishop.color);
}

TEST_F(BoardControllerTest, SetBlackBishopTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto bishop = Square{Piece::BISHOP, Color::BLACK};
    ASSERT_TRUE(board[7][5].piece == bishop.piece && board[7][2].color == bishop.color);
    ASSERT_TRUE(board[7][2].piece == bishop.piece && board[7][5].color == bishop.color);
}

TEST_F(BoardControllerTest, SetWhiteQueenTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto queen = Square{Piece::QUEEN, Color::WHITE};
    ASSERT_TRUE(board[0][3].piece == queen.piece && board[0][3].color == queen.color);
}

TEST_F(BoardControllerTest, SetBlackQueenTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto queen = Square{Piece::QUEEN, Color::BLACK};
    ASSERT_TRUE(board[7][3].piece == queen.piece && board[7][3].color == queen.color);
}

TEST_F(BoardControllerTest, SetWhiteKingTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto king = Square{Piece::KING, Color::WHITE};
    ASSERT_TRUE(board[0][4].piece == king.piece && board[0][4].color == king.color);
}

TEST_F(BoardControllerTest, SetBlackKingTest) {
    auto boardController = BoardController{};
    boardController.initialSetup(board);
    auto king = Square{Piece::KING, Color::BLACK};
    ASSERT_TRUE(board[7][4].piece == king.piece && board[7][4].color == king.color);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}