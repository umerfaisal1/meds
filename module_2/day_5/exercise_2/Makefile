CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = main
OBJ = main.o

.PHONY: all debug

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

debug: CFLAGS += -DDEBUG
debug: all