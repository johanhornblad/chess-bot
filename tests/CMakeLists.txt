# filepath: /home/johanhornblad/Projects/chessBot/chess-bot/tests/CMakeLists.txt

# Add the test source file
add_executable(main_test main_test.cpp)

# Link GoogleTest to the test executable
target_link_libraries(main_test gtest gtest_main)

# Add the test
add_test(NAME MyTests COMMAND main_test)

#New Test File
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

#New Test File
# Add the test source file
add_executable(pawn_logic_test pawn_logic_test.cpp ../src/pawn_logic.cpp ../src/piece_logic_factory.cpp)

# Link GoogleTest to the test executable
target_link_libraries(pawn_logic_test gtest gtest_main)

# Add the test
add_test(NAME PawnLogicTest COMMAND pawn_logic_test)
