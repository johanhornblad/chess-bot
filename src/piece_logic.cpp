#include "../inc/piece_logic.h"

const int MAX_COL = 7;
const int MAX_ROW = 7;
const int MIN_COL = 0;
const int MIN_ROW = 0;

bool PieceLogic::isWithinBoard(int row, int col) const {
    return row <= MAX_ROW && col <= MAX_COL && row>= MIN_ROW && col >= MIN_COL;
}

bool PieceLogic::isAvailableSquare(const Square& square, Color color) const {
    return square.piece == Piece::EMPTY && color != square.color;
}