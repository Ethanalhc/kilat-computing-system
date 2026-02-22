///////////////////////////////////////////////////////////////////////
// MAIN.c - Provide an entrypoint and control center to the program. //
///////////////////////////////////////////////////////////////////////

#include "ISA/isa.h"
#include "CPU/cpu.h"
#include "CPU/Memory/memory.h"
#include "includes.h"

int main() {
    // Declare Components
    CPU cpu;

    // Init Components
    CPU_Init(&cpu);

    MEM_Load8(0x04, 128, cpu.memory);
    MEM_Load8(0x04, 129, cpu.memory);
    MEM_Load8(0x04, 130, cpu.memory);
    MEM_Load8(0x04, 131, cpu.memory);
    MEM_Load8(0x02, 132, cpu.memory);
    MEM_Load8(0x04, 133, cpu.memory);
    MEM_Load8(0x04, 134, cpu.memory);
    MEM_Load8(0x02, 135, cpu.memory);
    MEM_Load8(0x03, 136, cpu.memory);
    MEM_Load8(0x01, 137, cpu.memory);
    MEM_Load8(0x03, 138, cpu.memory);
    MEM_Load8(0x02, 139, cpu.memory);
    MEM_Load8(0x04, 140, cpu.memory);
    MEM_Load8(0xFF, 141, cpu.memory);

    uint8_t opcode;
    func_ptr func;

    // Fetch -> Execute -> Decode Cycle
    int on = 1;
    while (on) {
        // Fetch
        opcode = CPU_Fetch(&cpu);
        cpu.PC++;

        // Decode
        if (opcode == 255) {
            on = 0;
            break;
        }

        opcode = (int)opcode;
        func = instructions[opcode];

        // Execute
        func(&cpu);
    }

    MEM_Dump(0, cpu.memory);

    free(cpu.memory);

    return 0;
}