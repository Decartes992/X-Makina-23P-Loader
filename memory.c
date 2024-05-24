#include <stdio.h>
#include "loader.h"

unsigned short IMEM[IMEM_SIZE / 2]; // 64 KiB of word-addressable instruction memory
unsigned char DMEM[DMEM_SIZE];      // 64 KiB of byte-addressable data memory

void displayMemory(unsigned char *memory, int start, int end) {
    for (int i = start; i < end; i += HEX_BASE) {
        printf("%04X: ", i);
        for (int j = 0; j < HEX_BASE; j++) {
            if (i + j <= end) {
                printf("%02X ", memory[i + j]);
            } else {
                printf("   ");
            }
        }
        printf(" ");
        for (int j = 0; j < HEX_BASE; j++) {
            if (i + j <= end) {
                unsigned char c = memory[i + j];
                if (c >= ASCII_PRINTABLE_START && c <= ASCII_PRINTABLE_END) { // Printable ASCII range
                    printf("%c", c);
                } else {
                    printf(".");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    getchar();
}