# Makefile for Matrix-Operations

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g
TARGET   := matrix-ops
SRCS     := main.cpp matrix.cpp
OBJS     := $(SRCS:.cpp=.o)

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) results.csv
	@echo "Clean complete."
