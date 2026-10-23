#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "lib.h"

void run(void) {
    Chunk chunk = Chunk_new();
    Chunk_write(&chunk, OP_RETURN);

    disassemble_chunk(&chunk, "test chunk");

    Chunk_delete(&chunk);
}
