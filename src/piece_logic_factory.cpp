#include "../inc/piece_logic_factory.h"
#include "../inc/pawn_logic.h"
#include "../inc/rook_logic.h"
#include "../inc/bishop_logic.h"
#include "../inc/queen_logic.h"
#include "../inc/knight_logic.h"
#include "../inc/king_logic.h"

std::unique_ptr<PieceLogic> PieceLogicFactory::getPieceLogic(Piece piece) const {
    switch (piece)
    {
    case Piece::PAWN :
        return std::make_unique<PawnLogic>();
    case Piece::ROOK :
        return std::make_unique<RookLogic>();
    case Piece::KNIGHT: 
        return std::make_unique<KnightLogic>();    
    case Piece::BISHOP: 
        return std::make_unique<BishopLogic>();
    case Piece::QUEEN : 
        return std::make_unique<QueenLogic>();
    case Piece::KING :
        return std::make_unique<KingLogic>();
    
    default:
        break;
    }

}