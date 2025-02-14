#ifndef QUEEN_LOGIC_H
#define QUEEN_LOGIC_H

#include "straight_logic.h"
#include "diagonal_logic.h"

class QueenLogic : public StraightLogic, public DiagonalLogic {

    public:
    std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;

};

#endif // QUEEN_H