#ifndef SQUARE_H
#define SQUARE_H

enum Piece{EMPTY,PAWN,KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum Color {WHITE, BLACK, NONE};

struct Square
{
 Piece piece;
 Color color;
};



#endif //SQUARE_H