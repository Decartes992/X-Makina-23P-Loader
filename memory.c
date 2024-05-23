//
// Created by Decartes on 2024-05-23.
//
#include <stdio.h>
#include "loader.h"

unsigned short IMEM[IMEM_SIZE]; // 64 KiB of word-addressable instruction memory
unsigned char DMEM[DMEM_SIZE];  // 64 KiB of byte-addressable data memory

void displayMemory() {
    printf("Instruction Memory (IMEM):\n");
    for (int i = 0; i < IMEM_SIZE; i += 16) {
        printf("%04X: ", i);
        for (int j = 0; j < 16; j++) {
            printf("%04X ", IMEM[i + j]);
        }
        printf("\n");
    }

    printf("\nData Memory (DMEM):\n");
    for (int i = 0; i < DMEM_SIZE; i += 16) {
        printf("%04X: ", i);
        for (int j = 0; j < 16; j++) {
            printf("%02X ", DMEM[i + j]);
        }
        printf("\n");
    }
}
