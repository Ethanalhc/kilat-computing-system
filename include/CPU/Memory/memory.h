#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include <stdio.h>
#include "CPU/cpu.h"

typedef struct {
    uint32_t start;
    uint32_t end;
    uint32_t (*read32)(uint32_t addr);
    int (*write32)(uint32_t addr, uint32_t val);
} MemoryRegion;

typedef struct {
    uint8_t *memory;
    MemoryRegion memory_mapping[3];
} Memory;

uint32_t MEM_RAM_Read32(uint32_t addr) {}
int MEM_RAM_Write32(uint32_t addr, uint32_t val) {}
uint32_t MEM_ROM_Read32(uint32_t addr) {}
int MEM_ROM_Write32(uint32_t addr, uint32_t val) {}
uint32_t MEM_VRAM_Read32(uint32_t addr) {}
int MEM_VRAM_Write32(uint32_t addr, uint32_t val) {}

int CPU_MEM_LoadProgram(Memory *memory) {}

#endif // MEMORY_H