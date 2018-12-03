CFLAGS = -Wall -Werror -Wpedantic -Wextra -Wshadow -Isrc
CC = gcc -std=c11

SRC=$(wildcard src/*.c)

all: example

example: $(SRC) examples/example.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	@rm -f example