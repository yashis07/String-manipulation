CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include -I googletest/googletest/include
LDFLAGS = -Lgoogletest/build/lib -lgtest -lgtest_main -pthread
OBJ_DIR = obj
BIN_DIR = bin

# Source files
UTILS_SRC = src/StringUtils.cpp
TEST_SRC = testsrc/StringUtilsTest.cpp

# Object files
UTILS_OBJ = $(OBJ_DIR)/StringUtils.o
TEST_OBJ = $(OBJ_DIR)/StringUtilsTest.o

# Executable name
EXECUTABLE = $(BIN_DIR)/teststrutils

.PHONY: all setup clean test

all: setup $(EXECUTABLE) test

# Setup the bin and obj directories
setup:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Compile the source files into object files
$(UTILS_OBJ): $(UTILS_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files to create the executable
$(EXECUTABLE): $(UTILS_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Execute the tests
test: $(EXECUTABLE)
	./$<

# Clean up the build directories
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)

