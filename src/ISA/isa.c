#include "ISA/isa.h"

int NOP(CPU *cpu) {
    return 0;
}
int LEFT(CPU *cpu) {
    cpu->MP -= 1;
    return 0;
}
int RIGHT(CPU *cpu) {
    cpu->MP += 1;
    return 0;
}
int DEC(CPU *cpu) {
    cpu->memory[cpu->MP] -= 1;
    return 0;
}
int INC(CPU *cpu) {
    cpu->memory[cpu->MP] += 1;
    return 0;
}

func_ptr instructions[5] = {NOP, LEFT, RIGHT, DEC, INC};