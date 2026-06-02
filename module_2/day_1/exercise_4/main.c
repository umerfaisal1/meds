#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t extract_field(uint32_t instruction, int high, int low)
{
    return (instruction >> low) & ((1U << (high - low + 1)) - 1);
}

void decode_instruction(uint32_t instruction)
{
    uint32_t opcode = extract_field(instruction, 6, 0);
    uint32_t rd = extract_field(instruction, 11, 7);
    uint32_t funct3 = extract_field(instruction, 14, 12);
    uint32_t rs1 = extract_field(instruction, 19, 15);
    uint32_t rs2 = extract_field(instruction, 24, 20);
    uint32_t funct7 = extract_field(instruction, 31, 25);

    printf("Instruction: 0x%08X\n", instruction);
    printf("opcode = 0x%02X (%u)\n", opcode, opcode);
    printf("rd     = x%u\n", rd);
    printf("funct3 = 0x%X\n", funct3);
    printf("rs1    = x%u\n", rs1);
    printf("rs2    = x%u\n", rs2);
    printf("funct7 = 0x%02X\n", funct7);
    printf("-----------------------------\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <RV32 instruction in hex>\n", argv[0]);
        return 1;
    }

    char *endptr;
    uint32_t instruction = (uint32_t)strtoul(argv[1], &endptr, 16);

    if (*endptr != '\0')
    {
        fprintf(stderr, "Invalid hexadecimal instruction.\n");
        return 1;
    }

    decode_instruction(instruction);

    return 0;
}