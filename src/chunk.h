#ifndef IRON_CHUNK_H
#define IRON_CHUNK_H

#include <stdint.h>
#include <stdlib.h>

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    size_t length;
    size_t capacity;
    uint8_t *code;
} Chunk;

Chunk Chunk_new(void);
void Chunk_delete(Chunk *chunk);
void Chunk_write(Chunk *chunk, uint8_t byte);

#endif // IRON_CHUNK_H
