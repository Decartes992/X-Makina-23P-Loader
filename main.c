//
// Created by Decartes on 2024-05-23.
//

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMEM_SIZE 65536
#define DMEM_SIZE 65536

unsigned short IMEM[IMEM_SIZE]; // 64 KiB of word-addressable instruction memory
unsigned char DMEM[DMEM_SIZE];  // 64 KiB of byte-addressable data memory

// Function to parse S-Records and load them into memory
void loadSRecord(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != 'S') continue; // Not an S-Record

        int count, address, checksum;
        sscanf(line + 2, "%2x%4x", &count, &address);

        if (line[1] == '0') {
            // S0 record: header
            printf("Header: %s\n", line + 8);
        } else if (line[1] == '1') {
            // S1 record: IMEM data
            for (int i = 0; i < count - 3; i += 2) {
                unsigned int data;
                sscanf(line + 8 + i * 2, "%2x", &data);
                IMEM[address++] = data;
            }
        } else if (line[1] == '2') {
            // S2 record: DMEM data
            for (int i = 0; i < count - 3; i++) {
                unsigned int data;
                sscanf(line + 8 + i * 2, "%2x", &data);
                DMEM[address++] = data;
            }
        } else if (line[1] == '9') {
            // S9 record: starting address
            printf("Starting address: %04X\n", address);
        }
    }
    fclose(file);
}

// Function to display memory contents
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

int main() {
    const char *filename = "program.xme";
    loadSRecord(filename);
    displayMemory();
    return 0;
}
