#include "../inc/pawn_logic.h"


std::vector<Move> PawnLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    auto availableMoves = std::vector<Move>{};

    int endRow1;
    int endCol1;

    int endRow2;
    int endCol2;

    if(color == Color::WHITE) {
       endRow1 = startRow + 1;
       endCol1 = startColumn;

       endRow2 = startRow + 2;
       endCol2 = startColumn;

    } else {
       endRow1 = startRow - 1;
       endCol1 = startColumn;

       endRow2 = startRow - 2;
       endCol2 = startColumn;

    }

    auto move1 = Move{startRow, startColumn, endRow1, endCol1, Piece::EMPTY, false, Piece::EMPTY };
    auto move2 = Move{startRow, startColumn, endRow2, endCol2, Piece::EMPTY, false, Piece::EMPTY };

    availableMoves.push_back(move1);
    availableMoves.push_back(move2);
    
    return availableMoves;
}


 std::vector<Move> PawnLogic::getCaptureMoves(int startRow, int startCol, Color color, const std::vector<std::vector<Square>>& board) const {
    
 };


