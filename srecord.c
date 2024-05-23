//
// Created by Decartes on 2024-05-23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loader.h"

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
