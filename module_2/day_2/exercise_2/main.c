#include <stdio.h>
#include <stdint.h>

#define NUM_REGS 32

void write_reg(uint32_t *regs, uint8_t rd, uint32_t value)
{
    if (rd != 0 && rd < NUM_REGS)
    {
        regs[rd] = value;
    }
}

uint32_t read_reg(const uint32_t *regs, uint8_t rs)
{
    if (rs < NUM_REGS)
    {
        return regs[rs];
    }
    return 0; // Invalid register index
}

int main()
{
    uint32_t regs[NUM_REGS] = {0};

    write_reg(regs, 5, 1234);
    write_reg(regs, 10, 5678);

    printf("x5  = %u\n", read_reg(regs, 5));
    printf("x10 = %u\n", read_reg(regs, 10));

    // Attempt to write to x0
    write_reg(regs, 0, 9999);

    printf("x0  = %u\n", read_reg(regs, 0));

    return 0;
}