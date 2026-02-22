#include "includes.h"

typedef struct {
    uint32_t r[16];
    uint32_t PC;
    uint8_t *memory;
} CPU;

int CPU_Init(CPU *cpu);
uint8_t CPU_Fetch(CPU *cpu);