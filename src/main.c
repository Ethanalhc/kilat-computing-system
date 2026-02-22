///////////////////////////////////////////////////////////////////////
// MAIN.c - Provide an entrypoint and control center to the program. //
///////////////////////////////////////////////////////////////////////

#include "CPU/cpu.h"
#include "CPU/Memory/memory.h"
#include "includes.h"

int main() {
    // Declare Components
    CPU cpu;

    // Init Components
    CPU_Init(&cpu);

    MEM_Load8(0b100, 0, cpu.memory);
    MEM_Load8(0b100, 1, cpu.memory);
    MEM_Load8(0b100, 2, cpu.memory);
    MEM_Load8(0b100, 3, cpu.memory);
    MEM_Load8(0b10, 4, cpu.memory);
    MEM_Load8(0b100, 5, cpu.memory);
    MEM_Load8(0b100, 6, cpu.memory);
    MEM_Load8(0b10, 7, cpu.memory);
    MEM_Load8(0b11, 8, cpu.memory);
    MEM_Load8(0b1, 9, cpu.memory);
    MEM_Load8(0b11, 10, cpu.memory);
    MEM_Load8(0b10, 11, cpu.memory);
    MEM_Load8(0b100, 12, cpu.memory);
    MEM_Load8(0b11111111, 13, cpu.memory);

    uint8_t opcode;

    // Fetch -> Execute -> Decode Cycle
    int on = 1;
    while (on) {
        // Fetch
        opcode = CPU_Fetch(&cpu);
        cpu.PC++;
        
        // Decode
        CPU_Decode(opcode);
    }

    free(cpu.memory);

    return 0;
}