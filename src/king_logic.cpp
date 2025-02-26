#include "../inc/king_logic.h"


std::vector<Move> KingLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    std::vector<Move> availableMoves {};
    moveForward(startRow, startColumn, color, board, availableMoves);
    moveBackward(startRow, startColumn, color, board, availableMoves);
    moveRight(startRow, startColumn, color, board, availableMoves);
    moveLeft(startRow, startColumn, color, board, availableMoves);
    moveDiagonallyUpRight(startRow, startColumn, color, board, availableMoves);
    moveDiagonallyUpLeft(startRow, startColumn, color, board, availableMoves);
    moveDiagonallyDownRight(startRow, startColumn, color, board, availableMoves);
    moveDiagonallyDownLeft(startRow, startColumn, color, board, availableMoves);

    return availableMoves;
}

void KingLogic::moveForward(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::HORIZONTAL_NONE, Vertical::FORWARD, availableMoves, board);
}

void KingLogic::moveBackward(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::HORIZONTAL_NONE, Vertical::BACKWARD, availableMoves, board);
}

void KingLogic::moveRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::RIGHT, Vertical::VERTICAL_NONE, availableMoves, board);
}

void KingLogic::moveLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::LEFT, Vertical::VERTICAL_NONE, availableMoves, board);
}

void KingLogic::moveDiagonallyUpRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::RIGHT, Vertical::FORWARD, availableMoves, board);
}

void KingLogic::moveDiagonallyUpLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::LEFT, Vertical::FORWARD, availableMoves, board);
}

void KingLogic::moveDiagonallyDownRight(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::RIGHT, Vertical::BACKWARD, availableMoves, board);
}

void KingLogic::moveDiagonallyDownLeft(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board, std::vector<Move>& availableMoves) const {
    movePiece(startRow, startColumn, color, Horizontal::LEFT, Vertical::BACKWARD, availableMoves, board);
    
}

void KingLogic::movePiece(int startRow, int startCol, Color color, Horizontal horizontalDirection, Vertical verticalDirection, std::vector<Move>& availableMoves, const std::vector<std::vector<Square>>& board) const {
    int nextRow = moveVerticalIndex(startRow, verticalDirection, color);
    int nextCol = moveHorizontalIndex(startCol, horizontalDirection, color);
    if(isWithinBoard(nextRow, nextCol) && isAvailableSquare(board[nextRow][nextCol], color)) {
        Square nextSquare = board[nextRow][nextCol];
        auto move = createMove(startRow, startCol, color, nextSquare, nextRow, nextCol);
        availableMoves.push_back(move);
    }
}