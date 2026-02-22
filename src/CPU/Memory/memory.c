#include "CPU/Memory/memory.h"

uint8_t MEM_Read8(uint32_t addr, uint8_t *memory) {
    return memory[(int)addr]; 
}

int MEM_Load8(uint8_t data, uint32_t addr, uint8_t *memory) {
    if (addr >= 256*1024*1024) {
        fprintf(stderr, "Address out of range!");
        return 1;
    }

    memory[addr] = data;
    return 0;
}

int MEM_Dump(uint32_t addr, uint8_t *memory) {
    for (int row = 0; row < 4; row++) {
        printf("0x%08X: ", (uint32_t)addr+(row*16));
        for (int column = 0; column < 16; column++) {
            printf("%02X ", MEM_Read8(addr+column+(row*16), memory));
        }
        printf("\n");
    }
}