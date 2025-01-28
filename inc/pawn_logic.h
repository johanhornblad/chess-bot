#ifndef PAWN_LOGIC_H
#define PAWN_LOGIC_H

#include "piece_logic.h"


class PawnLogic: public PieceLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;
    private:
        std::vector<Move> getCaptureMoves(int startRow, int startCol, Color color, const std::vector<std::vector<Square>>& board) const;

};



#endif // PAWN_LOGIC_H