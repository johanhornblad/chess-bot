#include "../inc/pawn_logic.h"
#include <iostream>



constexpr int MAX_COL = 7;
constexpr int MAX_ROW = 7;
constexpr int MIN_ROW = 0;
constexpr int PAWN_START_ROW_WHITE = 1;
constexpr int PAWN_START_ROW_BLACK = 6;



std::vector<Move> PawnLogic::getAvaiableMoves(int startRow, int startColumn, Color color, const std::vector<std::vector<Square>>& board) const {
    auto availableMoves = std::vector<Move>{};

    int endRow;
    int endCol;


    if(color == Color::WHITE) {
       endRow = startRow + 1;
       endCol = startColumn;

    } else {
       endRow = startRow - 1;
       endCol = startColumn;
    }
   
    if(squareIsEmpty(board[endRow][endCol])) {
        bool isPromotion = isPawnPromotion(endRow, endCol, color);
        Piece promotionPiece = isPromotion ? Piece::QUEEN : Piece::EMPTY;
        auto move = Move{startRow, startColumn, endRow, endCol, Piece::EMPTY, isPromotion, promotionPiece};
        availableMoves.push_back(move);
    }
    
    addIfInitialMove(startRow, startColumn, color, availableMoves, board);
    getCaptureMoves(startRow, startColumn, availableMoves, color, board);

    
    return availableMoves;
}

void PawnLogic::getCaptureMoves(int startRow, int startCol, std::vector<Move>& moves, Color color, const std::vector<std::vector<Square>>& board) const {
    int endRow = color == Color::WHITE ? startRow + 1: startRow - 1;
    int endColLeft = color == Color::WHITE ? startCol - 1 : startCol + 1;
    int endcolRight =  color == Color::WHITE ? startCol + 1 : startCol - 1; 

    auto  possibleEnemyLeft = board[endRow][endColLeft];
    auto possibleEnemyRight = board[endRow][endcolRight];

    if(isEnemy(possibleEnemyLeft, color )) {
        bool isPromotion = isPawnPromotion(endRow, endColLeft, color);
        Piece promotionPiece = isPromotion ? Piece::QUEEN : Piece::EMPTY;
        moves.push_back(Move{startRow, startCol, endRow, endColLeft, possibleEnemyLeft.piece, isPromotion, promotionPiece });
    }
    if(isEnemy(possibleEnemyRight, color) ) {
        bool isPromotion = isPawnPromotion(endRow, endColLeft, color);
        Piece promotionPiece = isPromotion ? Piece::QUEEN : Piece::EMPTY;
        moves.push_back(Move{startRow, startCol, endRow, endcolRight, possibleEnemyRight.piece, isPromotion, promotionPiece });
    }
 };

 bool PawnLogic::isEnemy(const Square& square, Color color) const {
    return square.color != color && square.color != Color::NONE;
 }

 void PawnLogic::addIfInitialMove(int startRow, int startCol, Color color, std::vector<Move>& moves, const std::vector<std::vector<Square>>& board) const {
    int endRow;
    int endCol = startCol;

    if(color == Color::WHITE) {
        if(startRow == PAWN_START_ROW_WHITE) {
            endRow = startRow + 2;
            if(squareIsEmpty(board[endRow][endCol])) {
                auto move = Move{startRow, startCol, endRow, endCol, Piece::EMPTY, false, Piece::EMPTY };
                moves.push_back(move);
            }
        } 
    } else {
        if(startRow == PAWN_START_ROW_BLACK) {
            
            endRow = startRow - 2;
            if(squareIsEmpty(board[endRow][endCol])) {
                auto move = Move{startRow, startCol, endRow, endCol, Piece::EMPTY, false, Piece::EMPTY };
                moves.push_back(move);
            }
        }
    }
 }

bool PawnLogic::isPawnPromotion(int row, int col, Color color) const {
    if(color == Color::WHITE) {
        return row == MAX_ROW;
    } else {
        return row == MIN_ROW;
    }
 
}

 bool PawnLogic::squareIsEmpty(const Square& square) const {
    return square.piece == Piece::EMPTY;
 }


