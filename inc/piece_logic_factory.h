#ifndef PIECE_LOGIC_FACTORY_H
#define PIECE_LOGIC_FACTORY_H

#include "piece_logic.h"
#include <memory>

class PieceLogicFactory {
    public:
        std::unique_ptr<PieceLogic> getPieceLogic(Piece piece) const;

};



#endif //PIECE_LOGIC_FACTORY_H