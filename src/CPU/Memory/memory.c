#include <inttypes.h>
#include "CPU/Memory/memory.h"

uint8_t MEM_Read8(uint32_t addr, uint8_t *memory) {
    uint8_t buffer = 0;
    for (int i = 0; i < 8; i++) {
        buffer += memory[(int)addr+i];
    }
    return buffer;
}