#include "../inc/board_controller.h"
#include <ctype.h>
#include <iostream>


void BoardController::initialSetup(std::vector<std::vector<Square>>& board) {
    setupPawns(board);
    setupRooks(board);
    setupKnights(board);
    setupBishops(board);
    setupQueens(board);
    setupKings(board);
}

void BoardController::printBoard(std::vector<std::vector<Square>>& board, Color playerColor) {
  if (playerColor == Color::WHITE) {
    for (int i = 7; i >= 0; i--) {
      std::cout << i + 1 << " ";
      printRow(board, i);
      std::cout << std::endl;
    }
  } else {
    for (int i = 0; i < 8; i++) {
      std::cout << i + 1 << " ";
      printRow(board, i);
      std::cout << std::endl;
    }
  }
  std::cout << "  ------------------------" << std::endl;
  std::cout << "  [A][B][C][D][E][F][G][H]" << std::endl;
}

void BoardController::printRow(std::vector<std::vector<Square>> &board, int i)
{
  for (int j = 0; j < 8; j++) {
    char pieceChar;
    switch (board[i][j].piece) {
      case PAWN:
        pieceChar = 'P';
        break;
      case KNIGHT:
        pieceChar = 'N';
        break;
      case BISHOP:
        pieceChar = 'B';
        break;
      case ROOK:
        pieceChar = 'R';
        break;
      case QUEEN:
        pieceChar = 'Q';
        break;
      case KING:
        pieceChar = 'K';
        break;
      default:
        pieceChar = ' ';
    }
    if (board[i][j].color == BLACK)
      pieceChar = tolower(pieceChar);
    std::cout << "[" << pieceChar << "]";
  }
}
void BoardController::setupPawns(std::vector<std::vector<Square>>& board) {
    auto whitePawn = Square{Piece::PAWN, Color::WHITE};
    auto blackPawn = Square{Piece::PAWN, Color::BLACK};
    for(int j = 0; j < 8; j++) {
      board[1][j] = whitePawn;
    }

    for(int j = 0; j < 8; j++) {
      board[6][j] = blackPawn;
    }
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

void BoardController::setupKnights(std::vector<std::vector<Square>>& board) {
   auto whiteKnight = Square{Piece::KNIGHT , Color::WHITE};
   auto blackKnight = Square{Piece::KNIGHT, Color::BLACK};
   
   // white
   board[0][1] = whiteKnight;
   board[0][6] = whiteKnight;

   //black
   board[7][1] = blackKnight;
   board[7][6] = blackKnight;

}

void BoardController::setupBishops(std::vector<std::vector<Square>>& board) {
  auto whiteBishop = Square{Piece::BISHOP, Color::WHITE};
  auto blackBishop = Square{Piece::BISHOP, Color::BLACK};
  
  board[0][2] = whiteBishop;
  board[0][5] = whiteBishop;
  
  
  board[7][2] = blackBishop;
  board[7][5] = blackBishop;

}

void BoardController::setupQueens(std::vector<std::vector<Square>>& board){
  auto whiteQueen = Square{Piece::QUEEN, Color::WHITE};
  auto blackQueen = Square{Piece::QUEEN, Color::BLACK};
  
  board[0][3] = whiteQueen;
  
  board[7][3] = blackQueen;

}

void BoardController::setupKings(std::vector<std::vector<Square>>& board) {
  auto whiteKing = Square{Piece::KING, Color::WHITE};
  auto blackKing = Square{Piece::KING, Color::BLACK};
  
  board[0][4] = whiteKing;
  
  board[7][4] = blackKing;
}


