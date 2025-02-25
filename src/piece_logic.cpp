#include "../inc/piece_logic.h"
#include <iostream>

const int MAX_COL = 7;
const int MAX_ROW = 7;
const int MIN_COL = 0;
const int MIN_ROW = 0;

bool PieceLogic::isWithinBoard(int row, int col) const {
    return row <= MAX_ROW && col <= MAX_COL && row>= MIN_ROW && col >= MIN_COL;
}

bool PieceLogic::isAvailableSquare(const Square& square, Color color) const {
    return square.piece == Piece::EMPTY || color != square.color;
}

Move PieceLogic::createMove(int startRow, int startColumn, Color color, const Square& endSquare, int endRow, int endColumn) const {
    return Move{startRow, startColumn, endRow, endColumn, endSquare.piece, false, Piece::EMPTY};
}

bool PieceLogic::isTakeMove(const Square& square, Color color) const{
    return square.piece != Piece::EMPTY && color != square.color;
}

void PieceLogic::movePiece(int startRow, int startCol, Color color, Horizontal horizontalDirection, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = moveVerticalIndex(startRow, verticalDirection, color);
    int nextCol = moveHorizontalIndex(startCol, horizontalDirection, color);
    while (isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
          Square nextSquare = board[nextRow][nextCol];
        auto move = createMove(startRow, startCol, color, nextSquare, nextRow, nextCol);
        availableMoves.push_back(move);
        if(isTakeMove(nextSquare, color)) break;
        
        nextRow = moveVerticalIndex(nextRow, verticalDirection, color);
        nextCol = moveHorizontalIndex(nextCol, horizontalDirection, color);
        
    }
}

int PieceLogic::moveVerticalIndex(int row, Vertical verticalDirection, Color color) const {
    if(verticalDirection == Vertical::FORWARD) {
          return color == Color::WHITE? row + 1: row - 1;
    } else if (verticalDirection == Vertical::BACKWARD) {
        return color == Color::WHITE? row - 1: row + 1;
    }
    return row;

}
int PieceLogic::moveHorizontalIndex(int column, Horizontal horizontalDirection, Color color) const {
    if(horizontalDirection == Horizontal::RIGHT) {
          return color == Color::WHITE? column + 1: column - 1;
    } else if (horizontalDirection == Horizontal::LEFT) {
        return color == Color::WHITE? column - 1: column + 1;
    }
    return column;
}