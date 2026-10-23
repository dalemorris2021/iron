#ifndef IRON_DEBUG_H
#define IRON_DEBUG_H

#include <stdint.h>

#include "chunk.h"

void disassemble_chunk(Chunk *chunk, const char *name);
uint32_t disassemble_instruction(Chunk *chunk, uint32_t offset);

#endif // IRON_DEBUG_H
