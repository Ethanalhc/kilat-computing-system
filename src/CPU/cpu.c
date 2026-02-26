#include "CPU/cpu.h"
#include "CPU/Memory/memory.h"

int CPU_Init(CPU *cpu) {
    cpu->memory = calloc(1, 256*1024*1024);
    cpu->PC = 0x8000000;
    cpu-> MP = 0;
    return 0;
}

uint32_t CPU_Fetch(CPU *cpu) {
    return MEM_Read32(cpu->PC, cpu->memory);
}