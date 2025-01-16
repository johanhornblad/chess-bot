#include <iostream>
#include <vector>

#include "../inc/square.h"




int main() {
    auto board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));

    std::cout << "Hello, World!" << std::endl;

    return 0;
}