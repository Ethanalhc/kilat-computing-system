To understand the opcode reference [format.md](format.md)

| Mnemonic | Opcode | Operands | Description |
|----------|--------|----------|-------------|
| NOP | 0x00000000 00000000 | -, - | Does nothing. |
| MPL | 0x00000100 00000000 | -, - | Moves the memory pointer 1 byte to the left. |
| MPR | 0x00000200 00000000 | -, - | Moves the memory pointer 1 byte to the right. |
| DEC | 0x00000300 00000000 | -, - | Decrements the current position pointed to by the memory pointer. |
| INC | 0x00000400 00000000 | -, - | Increments the current position pointed to by the memory pointer. |
| MOV | 0x010001rd 00000rs1 | rd, rs1 | Moves the value in rs1 to the register rd. rs1 will ussually be the memory pointer. |
| LOD | 0x030001rd mem_addr | rd, mem_addr | Moves the value in mem_addr to rd. |
| STR | 0x02000100 00000rs1 | -, rs1 | Move the value in rs1 to the address pointed to by the memory pointer. | 
| ADD
| SUB