#include "../inc/rook_logic.h"

 std::vector<Move> RookLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const{
    auto availableMoves = std::vector<Move>{};
    moveForward(startRow, startColumn, color, availableMoves, board);
    moveBackWards(startRow, startColumn, color, availableMoves, board);
    moveRight(startRow, startColumn, color, availableMoves, board);
    moveLeft(startRow, startColumn, color, availableMoves, board);
    return availableMoves;
 }