#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

void memory_dump(const uint8_t *mem, size_t size)
{
    const size_t bytes_per_line = 8;

    for (size_t i = 0; i < size; i += bytes_per_line)
    {

        // Print offset/address
        printf("0x%04zx: ", i);

        // Print hex bytes
        for (size_t j = 0; j < bytes_per_line; j++)
        {
            if (i + j < size)
                printf("%02X ", mem[i + j]);
            else
                printf("   ");
        }

        printf("\n");
    }
}

int main()
{
    uint8_t data[] = {
        0xDE,
        0xAD,
        0xBE,
        0xEF,
        0xCA,
        0xFE,
        0xBA,
        0xBE,
        0xAC,
        0xBC};

    memory_dump(data, sizeof(data));
    return 0;
}