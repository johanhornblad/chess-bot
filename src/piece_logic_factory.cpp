#include "../inc/piece_logic_factory.h"
#include "../inc/pawn_logic.h"

std::unique_ptr<PieceLogic> PieceLogicFactory::getPieceLogic(Piece piece) const {
    switch (piece)
    {
    case Piece::PAWN :
        return std::make_unique<PawnLogic>();
    case Piece::ROOK :
        break;

    case Piece::KNIGHT: 
        break;    
    case Piece::BISHOP: 
        break;
    case Piece::QUEEN : 
        break;
    case Piece::KING :
        break;
    
    default:
        break;
    }

}