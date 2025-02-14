#include "../inc/straight_logic.h"


void StraightLogic::moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::HORIZONTAL_NONE, Vertical::FORWARD, availableMoves, board);
}

void StraightLogic::moveBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::HORIZONTAL_NONE, Vertical::BACKWARD, availableMoves, board);

}

void StraightLogic::moveRight(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::RIGHT, Vertical::VERTICAL_NONE, availableMoves, board);

}

void StraightLogic::moveLeft(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    movePiece(startRow, startCol, color, Horizontal::LEFT, Vertical::VERTICAL_NONE, availableMoves, board);
}