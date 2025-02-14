
#ifndef STRAIGHT_LOGIC_H
#define STRAIGHT_LOGIC_H
#include "square.h"
#include <vector>
#include "move.h"
#include "piece_logic.h"


class StraightLogic : virtual public PieceLogic {

    public:
        void moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveRight(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveLeft(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
};

#endif // STRAIGHT_LOGIC_H