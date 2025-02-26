#ifndef KING_LOGIC_H
#define KING_LOGIC_H

#include "piece_logic.h"

class KingLogic: public PieceLogic {
    public:

         std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const override;

    private: 
        void moveForward(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveBackward(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveDiagonallyUpRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveDiagonallyUpLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveDiagonallyDownRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;
        void moveDiagonallyDownLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const;

        void movePiece(int startRow, int startCol, Color color, Horizontal horizontalDirection, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const override;


};

#endif // KING_LOGIC_H