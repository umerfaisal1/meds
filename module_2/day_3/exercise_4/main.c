#include <stdio.h>

typedef struct
{
    char a;
    int b;
    char c;
    short d;
} mixed_t;

typedef struct
{
    int b;
    short d;
    char a;
    char c;
} mixed_optimized_t;

int main(void)
{
    printf("mixed_t size            = %zu\n", sizeof(mixed_t));
    printf("mixed_optimized_t size  = %zu\n",
           sizeof(mixed_optimized_t));

    return 0;
}