#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint32_t raw;

    struct
    { // R-type
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        uint32_t rs2 : 5;
        uint32_t funct7 : 7;
    } r;

    struct
    { // I-type
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        int32_t imm : 12; // signed immediate
    } i;

} instruction_t;

int main(void)
{
    instruction_t instr;

    instr.raw = 0x00500113; // addi x2, x0, 5

    printf("Raw    : 0x%08X\n", instr.raw);
    printf("Opcode : 0x%02X\n", instr.i.opcode);
    printf("rd     : x%u\n", instr.i.rd);
    printf("funct3 : %u\n", instr.i.funct3);
    printf("rs1    : x%u\n", instr.i.rs1);
    printf("imm    : %d\n", instr.i.imm);

    return 0;
}
