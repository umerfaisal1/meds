#include <stdio.h>
#include <stdlib.h>

int global_var = 10;        // Data segment (initialized global)
static int static_var = 20; // Data segment (initialized static)

int main()
{
    int local_var = 30;                    // Stack
    int *malloc_var = malloc(sizeof(int)); // Heap

    *malloc_var = 40;

    printf("Address of global_var : %p\n", (void *)&global_var);
    printf("Address of static_var : %p\n", (void *)&static_var);
    printf("Address of local_var  : %p\n", (void *)&local_var);
    printf("Address of malloc_var : %p\n", (void *)malloc_var);

    free(malloc_var);
    return 0;
}