///////////////////////////////////////////////////////////////////////
// MAIN.c - Provide an entrypoint and control center to the program. //
///////////////////////////////////////////////////////////////////////

#include "CPU/cpu.h"
#include "ISA/isa.h"
#include "CPU/Memory/memory.h"
#include "includes.h"

int main(int argc, char *argv[]) {
    // Declare Components
    CPU cpu;

    // Init Components
    CPU_Init(&cpu);

    // Load File or Halt
    if (MEM_LoadFile(0x8000000, argv[1], cpu.memory)) {
        MEM_Load8(0xFF, 0x8000000, cpu.memory);
    }

    // Declare Variables
    uint32_t opcode, operands;

    // Fetch -> Execute -> Decode Cycle
    int on = 1;
    while (on) {
        // Fetch
        opcode = CPU_Fetch(&cpu);
        cpu.PC += 4;

        operands = CPU_Fetch(&cpu);
        cpu.PC += 4;

        // Decode & Execute
        switch (opcode & 0xFFFFFF00) {
            case 0xFFFFFF00: // Halt
                on = 0;
                break;
            case 0: // No Operation
                NOP();
                break;
            case 0x00000100: // LEFT
                MPL(&cpu);
                break;
            case 0x00000200: // RIGHT
                MPR(&cpu);
                break;
            case 0x00000300: // DECREMENT
                DEC(&cpu);
                break;
            case 0x00000400: // INCREMENT
                INC(&cpu);
                break;
            default: // No Recognisable Opcode
                printf("Could not find opcode");
        }
    }

    MEM_Dump(0, cpu.memory); // Memory Dump (Test)

    // Free the memory
    free(cpu.memory);

    return 0;
}