#include <iostream>
#include <vector>

#include "../inc/square.h"
#include "../inc/board_controller.h"




int main() {
    auto board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    auto boardController = BoardController{};

    boardController.initialSetup(board);

    boardController.printBoard(board, Color::WHITE);

    std::cout << "Hello, World!" << std::endl;

    return 0;
}