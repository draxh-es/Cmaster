CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined

# Usage: make run L=01-pointers-and-memory
L ?= 01-pointers-and-memory

build:
	$(CC) $(CFLAGS) $(L)/*.c -o $(L)/program

run: build
	./$(L)/program

clean:
	rm -f */program

.PHONY: build run clean
