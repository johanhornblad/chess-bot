#ifndef PAWN_LOGIC_H
#define PAWN_LOGIC_H

#include "piece_logic.h"


class PawnLogic: public PieceLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, const std::vector<std::vector<Square>>& board) const override;

};



#endif // PAWN_LOGIC_H