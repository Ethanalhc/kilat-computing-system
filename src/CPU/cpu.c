#include "CPU/cpu.h"
#include "CPU/Memory/memory.h"

int CPU_SystemPowerOn(CPU *cpu) {
    // Init CPU
    /// Init CPU Subsystems
    //// Memory
    cpu->memory = (uint8_t *)malloc(2 * 1024 * 1024 * 1024);

    cpu->memory->memory_mapping[0].start  = 0x00000000;
    cpu->memory->memory_mapping[0].end    = 0x3FFFFFFF;
    cpu->memory->memory_mapping[0].read32 = MEM_RAM_Read32;
    cpu->memory->memory_mapping[0].write32= MEM_RAM_Write32;

    cpu->memory->memory_mapping[1].start  = 0x40000000;
    cpu->memory->memory_mapping[1].end    = 0x5FFFFFFF;
    cpu->memory->memory_mapping[1].read32 = MEM_ROM_Read32;
    cpu->memory->memory_mapping[1].write32= MEM_ROM_Write32;

    cpu->memory->memory_mapping[2].start  = 0x60000000;
    cpu->memory->memory_mapping[2].end    = 0x7FFFFFFF;
    cpu->memory->memory_mapping[2].read32 = MEM_VRAM_Read32;
    cpu->memory->memory_mapping[2].write32= MEM_VRAM_Write32;

    // Begin Fetch-Decode-Execute Loop
}

int CPU_SystemShutDown(CPU *cpu) {
    // Init but backwards

    // CPU
    /// Shutdown CPU Subsystems
    //// Memory
    free(cpu->memory);
}