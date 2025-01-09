	# Makefile for a C++ project with main.cpp, matrix.h, and matrix.cpp
 
# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11
 
# Source files
SRC := main.cpp matrix.cpp
# Header files
HDR := matrix.h
# Output binary
TARGET := main
 
# Environment variables for configuration
BUILD_DIR ?= build
BIN_DIR ?= bin
TEST_DIR ?= tests
 
# Default target
.PHONY: all
all: build run
 
# Build the project
.PHONY: build
build:
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD_DIR)/$(TARGET)
 
# Run the project
.PHONY: run
run: build
	@echo "Running the program..."
	@$(BUILD_DIR)/$(TARGET)
 
# Clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)/*