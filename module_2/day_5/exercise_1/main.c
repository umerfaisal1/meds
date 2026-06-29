#include <stdio.h>
#include "decoder.h"

int main(void)
{
    unsigned int instruction = 0x00A50533;

    decode_instruction(instruction);

    return 0;
}