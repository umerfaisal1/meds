#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = malloc(sizeof(int));

    *ptr = 5;

    free(ptr);

    printf("%d\n", *ptr);   // using memory after free

    return 0;
}