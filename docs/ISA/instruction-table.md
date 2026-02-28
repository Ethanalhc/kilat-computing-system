To understand the opcode reference [format.md](format.md)

| Mnemonic | Opcode | Operands | Description |
|----------|--------|----------|-------------|
| **Memory:** |
| MPL | 0x00000100 00000000 | -, - | Moves the memory pointer 1 byte to the left. |
| MPR | 0x00000200 00000000 | -, - | Moves the memory pointer 1 byte to the right. |
| DEC | 0x00000300 00000000 | -, - | Decrements the current position pointed to by the memory pointer. |
| INC | 0x00000400 00000000 | -, - | Increments the current position pointed to by the memory pointer. |
| MOV | 0x010001rd 00000rs1 | rd, rs1 | Moves the value in rs1 to the register rd. rs1 will usually be the memory pointer. |
| LOD | 0x020001rd mem_addr | rd, mem_addr | Moves the value in mem_addr to rd. |
| STR | 0x01000100 00000rs1 | -, rs1 | Move the value in rs1 to the address pointed to by the memory pointer. | 
| **Arithmetic:** |
| ADD | 0x010002rd 00000rs1 | rd, rs1 | Sums the values in rs1 and rd. |
| SUB | 0x010003rd 00000rs1 | rd, rs1 | Subtracts the value in rs1 from the value in rd. |
| MUL | 0x010004rd 00000rs1 | rd, rs1 | Multiplies the values in rs1 and rd. |
| DIV | 0x010005rd 00000rs1 | rd, rs1 | Divides the value in rs1 from the value in rd.
| NEG | 0x000005rd 00000000 | rd, - | Negates the value in rd. |
| **Bitwise:** |
| NOT | 0x000006rd 00000000 | rd, - | Negates all the bits in rd. |
| AND | 0x010006rd 00000rs1 | rd, rs1 | Performs logical AND on all corresponding bit pairs in rd and rs1. |
| IOR | 0x010007rd 00000rs1 | rd, rs1 | Performs logical inclusive OR on all corresponding bit pairs in rd and rs1. |
| XOR | 0x010008rd 00000rs1 | rd, rs1 | Performs logical exclusive OR on all corresponding bit pairs in rd and rs1. |
| SHL | 0x000007rd 00000000 | rd, - | Shifts all the bits in rd one position left. |
| SHR | 0x000008rd 00000000 | rd, - | Shifts all the bits in rd one position right. |
| **Branch:** |
| JMP | 0x02000200 mem_addr | -, mem_addr | Jumps to mem_addr. |
| JEQ | 0x02000300 mem_addr | -, mem_addr | Jumps to mem_addr if the zero flag is set. |
| JNE | 0x02000300 mem_addr | -, mem_addr | Jumps to mem_addr if the zero flag is not set. |
| CAL | 0x02000400 mem_addr | -, mem_addr | Calls mem_addr as a subroutine. |
| RET | 0x00000900 00000000 | -, - | Returns from the subroutine. |
| **Other:** |
| NOP | 0x00000000 00000000 | -, - | Does nothing. |
| CMP | 0x00000Frd 00000000 | rd, - | Adjusts flags according to rd. |