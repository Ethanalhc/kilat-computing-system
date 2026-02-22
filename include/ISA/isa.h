#ifndef ISA_H
#define ISA_H

#include "includes.h"
#include "CPU/cpu.h"

typedef int (*func_ptr)(CPU *cpu);

int NOP(CPU *cpu);
int LEFT(CPU *cpu);
int RIGHT(CPU *cpu);
int DEC(CPU *cpu);
int INC(CPU *cpu);

extern func_ptr instructions[5];

#endif // ISA_H