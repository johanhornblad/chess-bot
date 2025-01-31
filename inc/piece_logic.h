#ifndef PIECE_LOGIC_H
#define PIECE_LOGIC_H

#include <vector>
#include "move.h"
#include "square.h"

class PieceLogic {

    public:
        virtual std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const = 0;
        
    protected:
        bool isWithinBoard(int row, int col) const;       
        bool isAvailableSquare(const Square& square, Color color) const;


};

#endif // PIECE_LOGIC_H