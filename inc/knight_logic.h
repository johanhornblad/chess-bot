#ifndef KNIGHT_LOGIC_H
#define KNIGHT_LOGIC_H
#include "piece_logic.h"


class KnightLogic: public PieceLogic {
    public:

        std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;

    private:
        void addIfValidMove(int startRow, int startColumn, Horizontal horizontalDirection, Vertical verticalDirection, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveLeft(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveRight(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveVertical(int startRow, int startCol, Color color, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        void moveHorizontal(int startRow, int startCol, Color color,Horizontal horizontalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        int moveKnightIndexForward(int index, Vertical verticalDirection, Horizontal horizontalDirection, Color color) const;




};
#endif // KNIGHT_LOGIC_H