# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = ../
NORMAL_DIR = $(SRC_DIR)/normal

# Source files
SOURCES = $(SRC_DIR)/board.cpp $(NORMAL_DIR)/ixigul.cpp

# Object files (keeping the full path for each object)
OBJECTS = $(SRC_DIR)/board.o $(NORMAL_DIR)/ixigul.o

# Output executable name
EXEC = ixigul_program

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Compile .cpp files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NORMAL_DIR)/%.o: $(NORMAL_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(SRC_DIR)/*.o $(NORMAL_DIR)/*.o $(EXEC)

# Phony targets (targets that aren't files)
.PHONY: all clean
