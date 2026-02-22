#ifndef CPU_H
#define CPU_H

#include <inttypes.h>
#include <CPU/Memory/memory.h>

typedef struct {
    // REGISTER FILE
    uint32_t r[16];
    uint32_t PC;
    uint32_t SP;
    uint32_t flags;
    // MEMORY
    Memory *memory;
} CPU;

int CPU_SystemPowerOn(CPU *cpu) {}

int CPU_SystemShutDown(CPU *cpu) {}

#endif // CPU_H