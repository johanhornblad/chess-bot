#include "../inc/board_controller.h"

void BoardController::initialSetup(std::vector<std::vector<Square>>& board) {
    auto whitePawn = Square{Piece::PAWN, Color::WHITE};
    auto blackPawn = Square{Piece::PAWN, Color::BLACK};

    for(int j = 0; j < 8; j++) {
      board[1][j] = whitePawn;
    }

    for(int j = 0; j < 8; j++) {
      board[6][j] = blackPawn;
    }
    setupRooks(board);
  
}

void BoardController::setupRooks(std::vector<std::vector<Square>>& board) {
  auto whiteRook = Square{Piece::ROOK, Color::WHITE};
  auto blackRook = Square{Piece::ROOK, Color::BLACK};
  // white
  board[0][0] = whiteRook;
  board[0][7] = whiteRook;
  // black
  board[7][0] = blackRook;
  board[7][7] = blackRook;
}
