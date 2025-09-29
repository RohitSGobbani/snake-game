# Makefile for Snake Game

CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lncurses

TARGET = snake
SRC = snake.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
