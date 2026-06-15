#include <stdint.h>
#include <stdio.h>

typedef enum
{
    OP_LOAD = 0x03,
    OP_MISC_MEM = 0x0F,
    OP_OP_IMM = 0x13,
    OP_AUIPC = 0x17,
    OP_STORE = 0x23,
    OP_OP = 0x33,
    OP_LUI = 0x37,
    OP_BRANCH = 0x63,
    OP_JALR = 0x67,
    OP_JAL = 0x6F,
    OP_SYSTEM = 0x73
} opcode_t;

const char *opcode_to_string(opcode_t op)
{
    switch (op)
    {
    case OP_LOAD:
        return "LOAD";
    case OP_MISC_MEM:
        return "MISC_MEM";
    case OP_OP_IMM:
        return "OP_IMM";
    case OP_AUIPC:
        return "AUIPC";
    case OP_STORE:
        return "STORE";
    case OP_OP:
        return "OP";
    case OP_LUI:
        return "LUI";
    case OP_BRANCH:
        return "BRANCH";
    case OP_JALR:
        return "JALR";
    case OP_JAL:
        return "JAL";
    case OP_SYSTEM:
        return "SYSTEM";
    default:
        return "UNKNOWN";
    }
}

int main(void)
{
    opcode_t ops[] = {
        OP_LOAD,
        OP_MISC_MEM,
        OP_OP_IMM,
        OP_AUIPC,
        OP_STORE,
        OP_OP,
        OP_LUI,
        OP_BRANCH,
        OP_JALR,
        OP_JAL,
        OP_SYSTEM};

    int n = sizeof(ops) / sizeof(ops[0]);

    for (int i = 0; i < n; i++)
    {
        printf("0x%02X -> %s\n",
               ops[i],
               opcode_to_string(ops[i]));
    }

    return 0;
}