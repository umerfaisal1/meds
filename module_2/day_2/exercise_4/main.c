#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void swap(uint32_t *a, uint32_t *b)
{
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(uint32_t *arr, size_t n)
{
    uint32_t *left = arr;
    uint32_t *right = arr + (n - 1);

    while (left < right)
    {
        swap(left, right);
        left++;
        right--;
    }
}

void display(const uint32_t *arr, size_t n)
{
    const uint32_t *p = arr;

    for (size_t i = 0; i < n; i++)
    {
        printf("%u, ", *(arr + i));
    }

    printf("\n");
}

int main()
{
    uint32_t data[] = {1, 2, 3, 4, 5};

    size_t n = sizeof(data) / sizeof(data[0]);

    display(data, n);
    reverse(data, n);
    display(data, n);

    return 0;
}