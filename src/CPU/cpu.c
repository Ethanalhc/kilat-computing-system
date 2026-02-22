#include "CPU/cpu.h"

int CPU_Init(CPU *cpu) {
    cpu->memory = calloc(1, 256*1024*1024);
    cpu->PC = 128;
    cpu-> MP = 0;
    return 0;
}

uint8_t CPU_Fetch(CPU *cpu) {
    if (cpu->memory[cpu->PC]) {
        return cpu->memory[cpu->PC];
    }

    return 0; // 0x00 is the NOP opcode.
}

