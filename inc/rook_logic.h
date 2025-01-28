#ifndef ROOK_LOGIC_H
#define ROOK_LOGIC_H

#include "piece_logic.h"


class PawnLogic: public PieceLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;
    private:
        /*void getCaptureMoves(int startRow, int startCol, std::vector<Move>& moves, Color color, const std::vector<std::vector<Square>>& board) const;
        bool isEnemy(const Square& square, Color color) const;
        void addIfInitialMove(int startRow, int startCol, Color color, std::vector<Move>& moves ) const;
        bool isPawnPromotion(int row, int col, Color color) const;*/

};



#endif // ROOK_LOGIC_H