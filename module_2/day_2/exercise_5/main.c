#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int strcat_safe(char *dest, size_t dest_size, const char *src)
{
    size_t dlen = 0;
    size_t slen = 0;

    // find length of dest
    while (dlen < dest_size && dest[dlen] != '\0')
    {
        dlen++;
    }

    // if no null terminator found in dest, it's invalid
    if (dlen == dest_size)
    {
        return -1;
    }

    // find length of src
    while (src[slen] != '\0')
    {
        slen++;
    }

    // check overflow
    if (dlen + slen + 1 > dest_size)
    {
        return -1;
    }

    // append src to dest
    size_t i = 0;
    while (i < slen)
    {
        dest[dlen + i] = src[i];
        i++;
    }

    // null terminate
    dest[dlen + slen] = '\0';

    return 0;
}

int main()
{
    char buffer[10] = "Hi";

    if (strcat_safe(buffer, sizeof(buffer), " Umer") == 0)
    {
        printf("%s\n", buffer);
    }
    else
    {
        printf("Error: buffer overflow risk\n");
    }

    return 0;
}