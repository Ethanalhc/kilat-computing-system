#ifndef ISA_H
#define ISA_H

#include "includes.h"
#include "CPU/cpu.h"

int NOP();
int MPL(CPU *cpu);
int MPR(CPU *cpu);
int DEC(CPU *cpu);
int INC(CPU *cpu);

#endif // ISA_H