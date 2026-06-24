#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));

    free(ptr);

    free(ptr);   // free again

    return 0;
}