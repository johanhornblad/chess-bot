
#ifndef PLAYER_H
#define PLAYER_H

#include "square.h"
#include <unordered_map>

class Player {
    public:
        Player(Color color);
        Color getPlayerColor() const;
        std::unordered_map<Piece, int> getPieces() const;


    private:
        Color color;
        std::unordered_map<Piece, int> pieces;

};


#endif //PLAYER_H