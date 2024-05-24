/*
Name: Iftekhar Rafi
ID: B00871031
Course: ECED 3403 Computer Architecture
Instructor: Larry Hughes

File Name: loader.h
File Purpose: This file contains the declarations of functions and memory arrays used in the project.
*/
#ifndef LOADER_H
#define LOADER_H

#define IMEM_SIZE 65536
#define DMEM_SIZE 65536
#define ARG_COUNT 2
#define HEX_BASE 16
#define ASCII_PRINTABLE_START 32
#define ASCII_PRINTABLE_END 126
#define HEADER_START 8
#define BYTE_SIZE 2
#define ASCII_SIZE 4
#define IMEM_SHIFT 1
#define DMEM_SHIFT 2
#define BYTE_MASK 0xFF
#define ADDRESS_SHIFT 1
#define DATA_SHIFT 8
#define LINE_SIZE 100

extern unsigned short IMEM[IMEM_SIZE / 2];
extern unsigned char DMEM[DMEM_SIZE];
void loadSRecord(const char *filename);
void displayMemory(unsigned char *memory, int start, int end);
void manager(int argc, char *argv[]);

#endif // LOADER_H