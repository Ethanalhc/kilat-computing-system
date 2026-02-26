// MEMORY UTILITY FUNCTIONS

#ifndef MEMORY_H
#define MEMORY_H

#include "includes.h"

uint8_t MEM_Read8(uint32_t addr, uint8_t *memory);
uint32_t MEM_Read32(uint32_t addr, uint8_t *memory);
int MEM_Load8(uint8_t data, uint32_t addr, uint8_t *memory);
int MEM_Dump(uint32_t addr, uint8_t *memory);
int MEM_LoadFile(uint32_t addr, char *filepath, uint8_t *memory);

#endif // MEMORY_H