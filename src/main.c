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

    if (MEM_LoadFile(0x8000000, argv[1], cpu.memory)) {
        MEM_Load8(0xFF, 0x8000000, cpu.memory);
    }
    MEM_Dump(cpu.PC, cpu.memory);

    uint32_t opcode;
    uint32_t operands;
    func_ptr func;

    // Fetch -> Execute -> Decode Cycle
    int on = 1;
    while (on) {
        // Fetch
        opcode = CPU_Fetch(&cpu);
        cpu.PC += 4;
        operands = CPU_Fetch(&cpu);
        cpu.PC += 4;

        printf("%08X\n", opcode);
        printf("%08X\n", operands);

        // Decode
        switch (opcode & 0xFFFFFF00) {
            case 0xFFFFFF00:
                on = 0;
                break;
            case 0:
                break;
            case 0x00000100:
                func = MPL;
                break;
            case 0x00000200:
                func = MPR;
                break;
            case 0x00000300:
                func = DEC;
                break;
            case 0x00000400:
                func = INC;
                break;
            default:
                printf("Could not find opcode");
        }

        // Execute
        func(&cpu);
    }

    MEM_Dump(0, cpu.memory);

    free(cpu.memory);

    return 0;
}