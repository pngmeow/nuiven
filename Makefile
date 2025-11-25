# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -O2 `pkg-config --cflags sdl2 SDL2_ttf`
LDFLAGS := `pkg-config --libs sdl2 SDL2_ttf`

# Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
TARGET := my_program

# Find all source files recursively
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)
	@rm -f $(OBJS)

# Link executable
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(LDFLAGS)

# Compile .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean everything
clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)

.PHONY: all clean
