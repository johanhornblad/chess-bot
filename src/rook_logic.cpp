#include "../inc/rook_logic.h"

const int MAX_COL = 7;
const int MAX_ROW = 7;
const int MIN_COL = 0;
const int MIN_ROW = 0;
 std::vector<Move> RookLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const{
    auto availableMoves = std::vector<Move>{};
    moveForward(startRow, startColumn, color, availableMoves, board);
    return availableMoves;
 }

  bool RookLogic::isWithinBoard(int row, int col) const {
   return row <= MAX_ROW && col <= MAX_COL;
  }

  void RookLogic::moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
      int nextRow = color == Color::WHITE ? startRow + 1 : startRow -1;
      int nextCol = startCol;
      auto nextSquare = board[nextRow][nextCol];
      while(isWithinBoard(nextRow, startCol) && isAvailableSquare(nextSquare, color)) {
         auto move = Move{startRow, startCol, nextRow, nextCol, Piece::EMPTY, false, Piece::EMPTY};
         availableMoves.push_back(move);
         nextRow = color == Color::WHITE ? nextRow + 1 : nextRow - 1; 
         nextSquare = board[nextRow][nextCol];
      }
  }

  bool RookLogic::isAvailableSquare(const Square& square, Color color) const {
      return square.piece == Piece::EMPTY && square.color != color;
  }