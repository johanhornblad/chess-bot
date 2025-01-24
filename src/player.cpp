#include "../inc/player.h"


Player::Player(Color color) : color(color){
    pieces = std::unordered_map<Piece, int>{};
}

 Color Player::getPlayerColor() const {
    return color;
 }

 std::unordered_map<Piece, int> Player::getPieces() const{
    return pieces;
 }