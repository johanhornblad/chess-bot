#ifndef PIECE_LOGIC_H
#define PIECE_LOGIC_H

#include <vector>
#include "move.h"
#include "square.h"

enum Horizontal{RIGHT, LEFT, HORIZONTAL_NONE};
enum Vertical{FORWARD, BACKWARD, VERTICAL_NONE};


class PieceLogic {

    public:
        virtual std::vector<Move> getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const = 0;
        
    protected:
        bool isWithinBoard(int row, int col) const;       
        bool isAvailableSquare(const Square& square, Color color) const;
        Move createMove(int startRow, int startColumn, Color color, const Square& endSquare, int endRow, int endColumn) const;
        void movePiece(int startRow, int startCol, Color color, Horizontal horizontalDirection, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const;
        int moveVerticalIndex(int column, Vertical verticalDirection, Color color) const;
        int moveHorizontalIndex(int row, Horizontal horizontalDirection, Color color) const;


};

#endif // PIECE_LOGIC_H