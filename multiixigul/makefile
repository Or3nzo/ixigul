# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = ../
MULTI_DIR = $(SRC_DIR)/multiixigul

# Source files
SOURCES = $(SRC_DIR)/board.cpp $(MULTI_DIR)/multiboard.cpp $(MULTI_DIR)/main.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Output executable name
EXEC = multiixigul

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXEC)

# Phony targets (targets that aren't files)
.PHONY: all clean
