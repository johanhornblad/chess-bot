#ifndef DIAGONAL_LOGIC_H
#define DIAGONAL_LOGIC_H

#include "piece_logic.h"

class DiagonalLogic : virtual public PieceLogic {
    public:
        void moveRightForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveRightBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveLeftForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveLeftBackwards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;

};

#endif // DIAGONAL_LOGIC_H