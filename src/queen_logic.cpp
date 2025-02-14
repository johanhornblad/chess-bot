#include "../inc/queen_logic.h"

std::vector<Move> QueenLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    auto availableMoves = std::vector<Move>{};

    //straight
    moveForward(startRow, startColumn, color, availableMoves, board);
    moveBackWards(startRow, startColumn, color, availableMoves, board);
    moveRight(startRow, startColumn, color, availableMoves, board);
    moveLeft(startRow, startColumn, color, availableMoves, board);

    //diagonal
    moveRightForward(startRow, startColumn, color, availableMoves, board);
    moveLeftForward(startRow, startColumn, color, availableMoves, board);
    moveRightBackWards(startRow, startColumn, color, availableMoves, board);
    moveLeftBackwards(startRow, startColumn, color, availableMoves, board);

    return availableMoves;

}