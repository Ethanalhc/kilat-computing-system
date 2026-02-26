#ifndef CPU_H
#define CPU_H

#include "includes.h"

typedef int (*func_ptr)();

typedef struct {
    uint32_t r[16];
    uint32_t PC;
    uint32_t MP; // Memory Pointer
    uint8_t *memory;
} CPU;

int CPU_Init(CPU *cpu);
uint32_t CPU_Fetch(CPU *cpu);

#endif // CPU_H