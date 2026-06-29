#include <stdint.h>
#include <stdio.h>

#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#ifdef RV64
typedef uint64_t reg_t;
#define REG_FMT "0x%016lX"
#else
typedef uint32_t reg_t;
#define REG_FMT "0x%08X"
#endif

typedef struct
{
    reg_t regs[32];
    reg_t pc;
} cpu_state_t;


void dump_registers(const cpu_state_t *cpu)
{
    DEBUG_PRINT("dumping registers...");
    printf("PC = ");

#ifdef RV64
    DEBUG_PRINT("64-bit CPU");
    printf(REG_FMT, (unsigned long)cpu->pc);
#else
    DEBUG_PRINT("32-bit CPU");
    printf(REG_FMT, cpu->pc);
#endif

    printf("\n\n");

    for (int i = 0; i < 32; i++)
    {
        printf("x%-2d = ",
               i);

#ifdef RV64
        printf(REG_FMT, (unsigned long)cpu->regs[i]);
#else
        printf(REG_FMT, cpu->regs[i]);
#endif

        if ((i + 1) % 2 == 0)
            printf("\n");
        else
            printf("    ");
    }
}

int main(void)
{
    cpu_state_t cpu = {0};

#ifdef RV64
    cpu.pc = 0x100000000ULL;
#else
    cpu.pc = 0x1000;
#endif

    for (int i = 0; i < 32; i++)
    {
        cpu.regs[i] = i;
    }

    dump_registers(&cpu);

    return 0;
}