#include <gtest/gtest.h>
#include "../inc/rook_logic.h"
#include "../inc/board_controller.h"
#include "../inc/piece_logic_factory.h"

class RookLogicTest : public ::testing::Test {
protected:

    // TODO: I have the take tests left.
    std::vector<std::vector<Square>> board = std::vector<std::vector<Square>>(8, std::vector<Square>(8, Square{Piece::EMPTY, Color::NONE}));
    BoardController boardController = BoardController{};
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    // Class members and helper functions can be declared here.
};

// Example test case
TEST_F(RookLogicTest, TestThatItCannoTMoveIfBlockedAllAround) {
    // Arrange
    boardController.initialSetup(board);
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(board[0][0].piece);
    auto startRow = 0;
    auto startCol = 0;
    
    // Act
        auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
        auto numOfMoves = static_cast<int>(moves.size());

    // Assert
    ASSERT_EQ(numOfMoves, 0);
}

TEST_F(RookLogicTest, TakeAsWhite) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;

    Square enemy = Square{Piece::ROOK, Color::BLACK};
    board[startRow + 1][startCol] = enemy;

    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow + 1 && move.endColumn == startCol ) {
            ASSERT_NE(move.capture, Piece::EMPTY);
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 1);
}

TEST_F(RookLogicTest, TakeAsBlack) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;

    Square enemy = Square{Piece::ROOK, Color::WHITE};
    board[startRow - 1][startCol] = enemy;

    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow - 1 && move.endColumn == startCol ) {
            ASSERT_NE(move.capture, Piece::EMPTY);
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 1);
}

TEST_F(RookLogicTest, CanMoveForwardAsWhite) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow > startRow && move.endColumn == startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 7-4);
}

TEST_F(RookLogicTest, CanMoveForwardAsBlack) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow < startRow && move.endColumn == startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 4);
}

TEST_F(RookLogicTest, CanMoveBackWardsAsWhite) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow < startRow && move.endColumn == startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 4);
}


TEST_F(RookLogicTest, CanMoveBackWardsAsBlack) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow > startRow && move.endColumn == startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 7-4);
}

TEST_F(RookLogicTest, CanMoveRightsAsBlack) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow && move.endColumn < startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 4);
}

TEST_F(RookLogicTest, CanMoveRightsAsWhite) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow && move.endColumn > startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 7-4);
}

TEST_F(RookLogicTest, CanMoveLeftsAsBlack) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::BLACK, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow && move.endColumn > startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 7-4);
}

TEST_F(RookLogicTest, CanMoveLeftsAsWhite) {
    // Arrange
    auto factory = PieceLogicFactory{};
    auto rookLogic = factory.getPieceLogic(Piece::ROOK);
    auto startRow = 4;
    auto startCol = 4;
    
    // Act
    auto moves = rookLogic->getAvaiableMoves(startRow, startCol, Color::WHITE, board);
    auto numOfMoves = static_cast<int>(moves.size());

    auto forwardMoveCounter = 0;
    for(const auto& move : moves ) {
        if(move.endRow == startRow && move.endColumn < startCol ) {
            forwardMoveCounter++;
        }
    }
    // Assert
    ASSERT_EQ(forwardMoveCounter, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}