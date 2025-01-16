#ifndef BOARD_CONTROLLER
#define BOARD_CONTROLLER

#include <vector>
#include "square.h"

class BoardController {
    public:
        void initialSetup(std::vector<std::vector<Square>>& board);
    private:
        void setupRooks(std::vector<std::vector<Square>>& board);



};
#endif //BOARD_CONTROLLER