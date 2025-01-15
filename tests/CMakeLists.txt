# filepath: /home/johanhornblad/Projects/chessBot/chess-bot/tests/CMakeLists.txt

# Add the test source file
add_executable(main_test main_test.cpp)

# Link GoogleTest to the test executable
target_link_libraries(main_test gtest gtest_main)

# Add the test
add_test(NAME MyTests COMMAND main_test)