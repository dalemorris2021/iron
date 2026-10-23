#ifndef IRON_CHUNK_H
#define IRON_CHUNK_H

#include <stdint.h>
#include <stdlib.h>

#include "value.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    size_t length;
    size_t capacity;
    uint8_t *code;
    ValueArray constants;
} Chunk;

Chunk Chunk_new(void);
void Chunk_delete(Chunk *chunk);
void Chunk_write(Chunk *chunk, uint8_t byte);
int Chunk_add_constant(Chunk *chunk, Value value);

#endif // IRON_CHUNK_H
