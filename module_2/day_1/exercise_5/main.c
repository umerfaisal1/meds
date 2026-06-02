#include <stdio.h>
#include <stdint.h>

int32_t sign_extend(uint32_t value, int bits)
{
    uint32_t sign_bit = 1U << (bits - 1);

    if (value & sign_bit)
    {
        value |= ~((1U << bits) - 1);
    }

    return (int32_t)value;
}

int main()
{
    uint32_t value = 0xFFF;
    int32_t result = sign_extend(value, 12);

    printf("Input  : 0x%03X\n", value);
    printf("Output : %d\n", result);
    printf("Hex    : 0x%08X\n", (uint32_t)result);

    return 0;
}