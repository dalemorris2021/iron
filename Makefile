CC = clang -std=c99
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror

RM = rm -f

SRC = src
SRCS = $(wildcard $(SRC)/*.c)

BUILD = build
OBJ = $(BUILD)/obj
BIN = $(BUILD)/bin
DIRS = $(BUILD) $(OBJ) $(BIN)

OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TARGET = $(BIN)/ironi

.PHONY: all clean run

all: $(DIRS) $(TARGET)

$(DIRS):
	mkdir -p $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)/* $(BIN)/*

run: all
	./$(TARGET)
