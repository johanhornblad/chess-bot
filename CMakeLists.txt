cmake_minimum_required(VERSION 3.10)
project(project-name)

enable_testing()

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

# Add the GoogleTest subdirectory
add_subdirectory(googletest)

# Add the tests subdirectory
add_subdirectory(tests)


# Add all source files here
set(SOURCES
    src/main.cpp
    src/board_controller.cpp
    # Add more source files as needed
)
# Add your source files
add_executable(main ${SOURCES})

