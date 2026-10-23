#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

static int simple_instruction(const char *name, uint32_t offset) {
    int count = printf("%s\n", name);
    if (count < 0) {
        exit(EXIT_FAILURE);
    }

    return offset + 1;
}

void disassemble_chunk(Chunk *chunk, const char *name) {
    int count = printf("== %s ==\n", name);
    if (count < 0) {
        exit(EXIT_FAILURE);
    }

    for (uint32_t offset = 0; offset < chunk->length;) {
        offset = disassemble_instruction(chunk, offset);
    }
}

uint32_t disassemble_instruction(Chunk *chunk, uint32_t offset) {
    int count = printf("%04d ", offset);
    if (count < 0) {
        exit(EXIT_FAILURE);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
    case OP_RETURN:
        return simple_instruction("OP_RETURN", offset);
    default:
        count = printf("unknown opcode %d\n", offset);
        if (count < 0) {
            exit(EXIT_FAILURE);
        }

        return offset + 1;
    }
}
