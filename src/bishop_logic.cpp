#include "../inc/bishop_logic.h"


 std::vector<Move> BishopLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    auto availableMoves = std::vector<Move>{};
    moveRightForward(startRow, startColumn, color, availableMoves, board);
    moveLeftForward(startRow, startColumn, color, availableMoves, board);
    moveRightBackWards(startRow, startColumn, color, availableMoves, board);
    moveLeftBackwards(startRow, startColumn, color, availableMoves, board);
    return availableMoves;
 }