#include "../inc/knight_logic.h"

std::vector<Move> KnightLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    auto availableMoves = std::vector<Move>{};
    
   moveForward(startRow, startColumn, color, availableMoves, board);
   moveBackWards(startRow, startColumn, color, availableMoves, board);
   moveLeft(startRow, startColumn, color, availableMoves, board);
   moveRight(startRow, startColumn, color, availableMoves, board);

return availableMoves; 
}

void KnightLogic::moveForward(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const{
    moveVertical(startRow, startCol, color, Vertical::FORWARD, availableMoves, board);
}
void KnightLogic::moveBackWards(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const{
    moveVertical(startRow, startCol, color, Vertical::BACKWARD, availableMoves, board);
}
void KnightLogic::moveLeft(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const{
    moveHorizontal(startRow, startCol, color, Horizontal::LEFT, availableMoves, board);

}
void KnightLogic::moveRight(int startRow, int startCol, Color color, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const{
    moveHorizontal(startRow, startCol, color, Horizontal::LEFT, availableMoves, board);
}


void KnightLogic::moveVertical(int startRow, int startCol, Color color, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    auto colRight = moveHorizontalIndex(startCol, Horizontal::RIGHT, color);
    auto colLeft = moveHorizontalIndex(startCol, Horizontal::LEFT, color);
    auto nextRow = startRow;
    nextRow = moveKnightIndexForward(startRow, verticalDirection, Horizontal::HORIZONTAL_NONE, color);

    if(isWithinBoard(nextRow, colRight) && isAvailableSquare(board[nextRow][colRight], color)) {
        auto move1 = createMove(startRow, startCol, color, board[nextRow][colRight], nextRow, colRight);
        availableMoves.push_back(move1);
        
    }
    if(isWithinBoard(nextRow, colLeft) && isAvailableSquare(board[nextRow][colLeft], color)) {
        auto move2 = createMove(startRow, startCol, color, board[nextRow][colLeft], nextRow, colLeft);
        availableMoves.push_back(move2);        
    }

}
void KnightLogic::moveHorizontal(int startRow, int startCol, Color color,Horizontal horizontalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {

    auto rowUp = moveVerticalIndex(startCol, Vertical::FORWARD, color);
    auto rowDown = moveVerticalIndex(startCol, Vertical::BACKWARD, color);
    auto nextCol = startCol;
    nextCol = moveKnightIndexForward(startRow, Vertical::VERTICAL_NONE, horizontalDirection, color);

    if(isWithinBoard(rowUp, nextCol) && isAvailableSquare(board[rowUp][nextCol], color)) {
        auto move1 = createMove(startRow, startCol, color, board[rowUp][nextCol], rowUp, nextCol);
        availableMoves.push_back(move1);

    }
    if(isWithinBoard(rowDown, nextCol) && isAvailableSquare(board[rowDown][nextCol], color)) {
        auto move2 = createMove(startRow, startCol, color, board[rowDown][nextCol], rowDown, nextCol);
        availableMoves.push_back(move2);
    }

}

int KnightLogic::moveKnightIndexForward(int index, Vertical verticalDirection, Horizontal horizontalDirection, Color color) const {
    int nextIndex = index;
    
    for(int i = 0; i < 2; i++) {
        if(verticalDirection != Vertical::VERTICAL_NONE) {
            nextIndex = moveVerticalIndex(nextIndex, verticalDirection, color);
        }
        if(horizontalDirection != Horizontal::HORIZONTAL_NONE) {
            nextIndex = moveHorizontalIndex(nextIndex, horizontalDirection, color);
        }
    }

    return nextIndex;
}