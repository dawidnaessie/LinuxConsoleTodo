# Makefile for todo-manager

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src

# Directories
SRC_DIR = src
BIN_DIR = bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Executable
TARGET = $(BIN_DIR)/program

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

# Run program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

