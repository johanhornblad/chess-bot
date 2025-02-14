# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -g -Iinc

# Source files
SRCS = src/main.cpp src/board_controller.cpp src/player.cpp src/piece_logic_factory.cpp src/pawn_logic.cpp src/rook_logic.cpp src/piece_logic.cpp src/straight_logic.cpp src/diagonal_logic.cpp src/bishop_logic.cpp


# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = main

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean