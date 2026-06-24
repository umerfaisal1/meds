#include <stdlib.h>

int main() {
    int *ptr = malloc(100);

    ptr[0] = 42;

    return 0;   // forgot free(ptr)
}