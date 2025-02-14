#include "../inc/diagonal_logic.h"


void DiagonalLogic::moveRightForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::RIGHT, Vertical::FORWARD, availableMoves, board);
}

void DiagonalLogic::moveLeftForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::LEFT, Vertical::FORWARD, availableMoves, board);
}

void DiagonalLogic::moveRightBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::RIGHT, Vertical::BACKWARD, availableMoves, board);

}

void DiagonalLogic::moveLeftBackwards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::LEFT, Vertical::BACKWARD, availableMoves, board);
}