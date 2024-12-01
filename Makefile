# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = .
LIBS_DIR = ./libs
BUILD_DIR = ./build

# Automatically find all source files
SRCS = $(wildcard $(SRC_DIR)/*.c $(LIBS_DIR)/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
TARGET = $(BUILD_DIR)/miishell

# Default target
all: $(TARGET)

# Create the build directory and link the final executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	rm -f $(OBJS) # Remove .o files after the build

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(OBJS)

# Phony targets
.PHONY: all clean
