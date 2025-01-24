
#ifndef MOVE_H
#define MOVE_H

#include "square.h"

struct Move {
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    Piece capture;
    bool isPawnPromotion;
    Piece promotionPiece;

    Move(int startRow, int startColumn, int endRow, int endColumn, Piece capture, bool isPawnPromotion, Piece promotionPiece) : 
    startRow(startRow),
    startColumn(startColumn),
    endRow(endRow),
    endColumn(endColumn),
    capture(capture),
    isPawnPromotion(isPawnPromotion),
    promotionPiece(promotionPiece) {};
};

#endif // MOVE_H