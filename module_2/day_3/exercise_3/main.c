#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    uint32_t regs[32];
    uint32_t pc;
} cpu_state_t;

static const char *abi_names[32] = {
    "zero", "ra", "sp", "gp",
    "tp", "t0", "t1", "t2",
    "s0/fp", "s1", "a0", "a1",
    "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3",
    "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11",
    "t3", "t4", "t5", "t6"};

void cpu_init(cpu_state_t *cpu)
{
    memset(cpu, 0, sizeof(cpu_state_t));
}

void reg_write(cpu_state_t *cpu, uint8_t reg, uint32_t value)
{
    if (reg == 0 || reg >= 32)
        return;

    cpu->regs[reg] = value;
}

uint32_t reg_read(const cpu_state_t *cpu, uint8_t reg)
{
    if (reg >= 32)
        return 0;

    return cpu->regs[reg];
}

void dump_registers(const cpu_state_t *cpu)
{
    printf("PC = 0x%08X\n\n", cpu->pc);

    for (int i = 0; i < 32; i++)
    {
        printf("x%-2d (%-5s) = 0x%08X",
               i,
               abi_names[i],
               cpu->regs[i]);

        if ((i + 1) % 2 == 0)
            printf("\n");
        else
            printf("    ");
    }
}

int main(void)
{
    cpu_state_t cpu;

    cpu_init(&cpu);

    reg_write(&cpu, 1, 0x12345678); // ra
    reg_write(&cpu, 2, 0x10000000); // sp
    reg_write(&cpu, 10, 42);        // a0
    reg_write(&cpu, 0, 9999);       // ignored

    cpu.pc = 0x80000000;

    printf("a0 = %u\n\n", reg_read(&cpu, 10));

    dump_registers(&cpu);

    return 0;
}