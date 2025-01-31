#include "../inc/straight_logic.h"


void StraightLogic::moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = color == Color::WHITE ? startRow + 1 : startRow - 1;
    int nextCol = startCol;
    Square nextSquare;
    while (isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
        auto move = Move{startRow, startCol, nextRow, nextCol, Piece::EMPTY, false, Piece::EMPTY};
        availableMoves.push_back(move);
        nextRow = color == Color::WHITE ? nextRow + 1 : nextRow - 1;
    }
}

void StraightLogic::moveBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = color == Color::WHITE ? startRow - 1 : startRow + 1;
    int nextCol = startCol;
    Square nextSquare;
    while (isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
        auto move = Move{startRow, startCol, nextRow, nextCol, Piece::EMPTY, false, Piece::EMPTY};
        availableMoves.push_back(move);
        nextRow = color == Color::WHITE ? nextRow - 1 : nextRow + 1;
    }
}

void StraightLogic::moveRight(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = startRow;
    int nextCol = color == Color::WHITE ? startCol + 1 : startCol - 1;
    Square nextSquare;
    while (isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
        auto move = Move{startRow, startCol, nextRow, nextCol, Piece::EMPTY, false, Piece::EMPTY};
        availableMoves.push_back(move);
        nextCol = color == Color::WHITE ? nextCol + 1 : nextCol - 1;
    }
}

void StraightLogic::moveLeft(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = startRow;
    int nextCol = color == Color::WHITE ? startCol - 1 : startCol + 1;
    Square nextSquare;
    while (isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
        auto move = Move{startRow, startCol, nextRow, nextCol, Piece::EMPTY, false, Piece::EMPTY};
        availableMoves.push_back(move);
        nextCol = color == Color::WHITE ? nextCol - 1 : nextCol + 1;
    }
}