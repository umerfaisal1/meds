#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint8_t opcode; // bits 6:0
    uint8_t rd;     // bits 11:7
    uint8_t funct3; // bits 14:12
    uint8_t rs1;    // bits 19:15
    uint8_t rs2;    // bits 24:20
    uint8_t funct7; // bits 31:25
} decoded_instr_t;

void decode_r_type(uint32_t raw, decoded_instr_t *out)
{
    out->opcode = raw & 0x7F;
    out->rd = (raw >> 7) & 0x1F;
    out->funct3 = (raw >> 12) & 0x07;
    out->rs1 = (raw >> 15) & 0x1F;
    out->rs2 = (raw >> 20) & 0x1F;
    out->funct7 = (raw >> 25) & 0x7F;
}

int main(void)
{
    uint32_t raw = 0x00A28233; // add x4, x5, x10

    decoded_instr_t instr;
    decode_r_type(raw, &instr);

    printf("opcode = 0x%02X\n", instr.opcode);
    printf("rd     = x%u\n", instr.rd);
    printf("funct3 = 0x%X\n", instr.funct3);
    printf("rs1    = x%u\n", instr.rs1);
    printf("rs2    = x%u\n", instr.rs2);
    printf("funct7 = 0x%02X\n", instr.funct7);

    return 0;
}