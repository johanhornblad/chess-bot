#ifndef ROOK_LOGIC_H
#define ROOK_LOGIC_H

#include "piece_logic.h"
#include "straight_logic.h"
#include "square.h"


class RookLogic: public StraightLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;
};



#endif // ROOK_LOGIC_H