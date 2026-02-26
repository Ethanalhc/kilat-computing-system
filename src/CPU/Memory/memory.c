#include "CPU/Memory/memory.h"

uint8_t MEM_Read8(uint32_t addr, uint8_t *memory) {
    return memory[(int)addr]; 
}

uint32_t MEM_Read32(uint32_t addr, uint8_t *memory) {
    uint32_t value = 0;
    value |= MEM_Read8(addr, memory) << 24;
    value |= MEM_Read8(addr + 1, memory) << 16;
    value |= MEM_Read8(addr + 2, memory) << 8;
    value |= MEM_Read8(addr + 3, memory);  
    return value;
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

int MEM_LoadFile(uint32_t addr, char *filepath, uint8_t *memory) {
    FILE *file = fopen(filepath, "rb");

    if (file == NULL) {
        printf("Failed to locate file!");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size < 0 || addr + file_size > 0x10000000) {
        fclose(file);
        printf("File too large for memory\n");
        return 1;
    }

    size_t bytes_read = fread(memory + addr, 1, file_size, file);
    fclose(file);

    if (bytes_read != (size_t)file_size) {
        printf("Failed to read entire file\n");
        return 1;
    }
    return 0;
}