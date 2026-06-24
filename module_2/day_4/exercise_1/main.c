#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MEM_SIZE 65536
#define DUMP_SIZE 64

unsigned char *memory;

int hex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

void load_file(const char *fname, unsigned char *mem) {
    FILE *f = fopen(fname, "r");
    if (!f) {
        perror("file");
        exit(1);
    }

    int c, h = -1;
    int addr = 0;

    while ((c = fgetc(f)) != EOF) {
        int v = hex((char)c);
        if (v == -1) continue;

        if (h == -1) {
            h = v;
        } else {
            mem[addr++] = (h << 4) | v;
            h = -1;

            if (addr >= MEM_SIZE) break;
        }
    }

    fclose(f);
}

void dump(unsigned char *mem) {
    for (int i = 0; i < DUMP_SIZE; i++) {
        if (i % 16 == 0) printf("\n%04X: ", i);
        printf("%02X ", mem[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s file\n", argv[0]);
        return 1;
    }

    memory = calloc(MEM_SIZE, 1);
    if (!memory) return 1;

    load_file(argv[1], memory);
    dump(memory);

    free(memory);
    return 0;
}