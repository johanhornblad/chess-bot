# filepath: /home/johanhornblad/Projects/chessBot/chess-bot/tests/CMakeLists.txt

# Add the test source file
add_executable(main_test main_test.cpp)

# Link GoogleTest to the test executable
target_link_libraries(main_test gtest gtest_main)

# Add the test
add_test(NAME MyTests COMMAND main_test)

#New Test File BoardControllerTest
# Add the test source file
add_executable(board_controller_test board_controller_test.cpp ../src/board_controller.cpp)

# Link GoogleTest to the test executable
target_link_libraries(board_controller_test gtest gtest_main)

# Add the test
add_test(NAME BoardControllerTest COMMAND board_controller_test)

#New Test File
# Add the test source file
add_executable(player_test player_test.cpp ../src/player.cpp)

# Link GoogleTest to the test executable
target_link_libraries(player_test gtest gtest_main)

# Add the test
add_test(NAME PlayerTest COMMAND player_test)

#New Test File PawnLogicTest
# Add the test source file
add_executable(pawn_logic_test pawn_logic_test.cpp ../src/pawn_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/rook_logic.cpp ../src/straight_logic.cpp ../src/piece_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(pawn_logic_test gtest gtest_main)

# Add the test
add_test(NAME PawnLogicTest COMMAND pawn_logic_test)

#New Test File RookLogicTest
# Add the test source file
add_executable(rook_logic_test rook_logic_test.cpp ../src/rook_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/pawn_logic.cpp ../src/piece_logic.cpp ../src/straight_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(rook_logic_test gtest gtest_main)

# Add the test
add_test(NAME RookLogicTest COMMAND rook_logic_test)

#New Test File BishopLogicTest
# Add the test source file
add_executable(bishop_logic_test bishop_logic_test.cpp ../src/rook_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/pawn_logic.cpp ../src/piece_logic.cpp ../src/straight_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(bishop_logic_test gtest gtest_main)

# Add the test
add_test(NAME BishopLogicTest COMMAND bishop_logic_test)

#New Test File QueenLogicTest
# Add the test source file
add_executable(queen_logic_test queen_logic_test.cpp ../src/rook_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/pawn_logic.cpp ../src/piece_logic.cpp ../src/straight_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(queen_logic_test gtest gtest_main)

# Add the test
add_test(NAME QueenLogicTest COMMAND queen_logic_test)

#New Test File KnightLogicTest
# Add the test source file
add_executable(knight_logic_test knight_logic_test.cpp ../src/rook_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/pawn_logic.cpp ../src/piece_logic.cpp ../src/straight_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(knight_logic_test gtest gtest_main)

# Add the test
add_test(NAME KnightLogicTest COMMAND knight_logic_test)

#New Test File KnightLogicTest
# Add the test source file
add_executable(king_logic_test king_logic_test.cpp ../src/rook_logic.cpp ../src/piece_logic_factory.cpp ../src/board_controller.cpp ../src/pawn_logic.cpp ../src/piece_logic.cpp ../src/straight_logic.cpp ../src/bishop_logic.cpp ../src/diagonal_logic.cpp ../src/queen_logic.cpp ../src/knight_logic.cpp ../src/king_logic.cpp)

# Link GoogleTest to the test executable
target_link_libraries(king_logic_test gtest gtest_main)

# Add the test
add_test(NAME KingLogicTest COMMAND king_logic_test)