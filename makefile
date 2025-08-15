# Makefile for your project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Source files and target
SRCS = sudoku.cpp
OBJS = $(SRCS:.c=.o)
TARGET = sudoku

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean