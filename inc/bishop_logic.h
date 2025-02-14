#ifndef BISHOP_LOGIC_H
#define BISHOP_LOGIC_H

#include "diagonal_logic.h"

class BishopLogic : public DiagonalLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;
};

#endif // BISHOP_LOGIC_H