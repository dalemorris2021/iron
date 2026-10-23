#ifndef IRON_DEBUG_H
#define IRON_DEBUG_H

#include <stdint.h>

#include "chunk.h"

void disassemble_chunk(Chunk *chunk, const char *name);
size_t disassemble_instruction(Chunk *chunk, size_t offset);

#endif // IRON_DEBUG_H
