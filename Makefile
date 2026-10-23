CC = clang -std=c99
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror

RM = rm -f

SRC = src
SRCS = $(wildcard *.c)

BUILD = build
OBJ = $(BUILD)/obj
BIN = $(BUILD)/bin
DIRS = $(BUILD) $(OBJ) $(BIN)

OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.obj, $(SRCS))
TARGET = $(BIN)/ironi

.PHONY: all clean run

all: $(TARGET) dirs

dirs: $(DIRS)
	mkdir -p $(DIRS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)/* $(BIN)/*

run: all
	./$(TARGET)
