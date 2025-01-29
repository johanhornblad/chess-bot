#ifndef ROOK_LOGIC_H
#define ROOK_LOGIC_H

#include "piece_logic.h"
#include "square.h"


class RookLogic: public PieceLogic {
    public:
        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;
    private:
        void moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        bool isWithinBoard(int row, int col) const;
        bool isAvailableSquare(const Square& square, Color color) const;

};



#endif // ROOK_LOGIC_H