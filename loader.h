//
// Created by Decartes on 2024-05-23.
//

#ifndef LOADER_H
#define LOADER_H

#define IMEM_SIZE 65536
#define DMEM_SIZE 65536

extern unsigned short IMEM[IMEM_SIZE];
extern unsigned char DMEM[DMEM_SIZE];

void loadSRecord(const char *filename);
void displayMemory();

#endif // LOADER_H
