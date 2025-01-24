#ifndef BOARD_CONTROLLER
#define BOARD_CONTROLLER

#include <vector>
#include "square.h"

class BoardController {
    public:
        void initialSetup(std::vector<std::vector<Square>>& board);
        void printBoard(std::vector<std::vector<Square>> &board, Color playerColor);
        void printRow(std::vector<std::vector<Square>> &board, int i);

    private:
        void setupPawns(std::vector<std::vector<Square>>& board);
        void setupRooks(std::vector<std::vector<Square>>& board);
        void setupKnights(std::vector<std::vector<Square>>& board);
        void setupBishops(std::vector<std::vector<Square>>& board);
        void setupQueens(std::vector<std::vector<Square>>& board);
        void setupKings(std::vector<std::vector<Square>>& board);




};
#endif //BOARD_CONTROLLER