CC = gcc
CFLAGS ?= -Wall -Wextra -g

SRC = main.c utils.c
OBJ = $(SRC:.c=.o)

TARGET = program

.PHONY: all clean test help

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

help:
	@echo "Available targets:"
	@echo "  make all    - Build the program"
	@echo "  make test   - Run the program"
	@echo "  make clean  - Remove generated files"
	@echo "  make help   - Show this help message"