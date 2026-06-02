#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <32-bit hex value>\n", argv[0]);
        return 1;
    }

    char *endptr;
    unsigned long value = strtoul(argv[1], &endptr, 16);

    if (*endptr != '\0') {
        fprintf(stderr, "Invalid hexadecimal input.\n");
        return 1;
    }

    uint32_t uval = (uint32_t)value;
    int32_t sval = (int32_t)uval;

    printf("Binary   : ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (uval >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");

    printf("Unsigned : %u\n", uval);
    printf("Signed   : %d\n", sval);
    printf("Hex      : 0x%08X\n", uval);

    return 0;
}