# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = sudokuGame

# For deleting the target
TARGET_DEL = sudokuGame.exe

# Source files
SRCS = sudokuBoard.cpp sudokuGame.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	$(TARGET)
# Clean ruule to remove generated files 
clean: 
	del $(TARGET_DEL) $(OBJS)