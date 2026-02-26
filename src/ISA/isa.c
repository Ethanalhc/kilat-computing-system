#include "ISA/isa.h"

int NOP() {
    return 0;
}
int MPL(CPU *cpu) {
    cpu->MP -= 1;
    return 0;
}
int MPR(CPU *cpu) {
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
