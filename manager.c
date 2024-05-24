/*
Name: Iftekhar Rafi
ID: B00871031
Course: ECED 3403 Computer Architecture
Instructor: Larry Hughes

File Name: manager.c
File Purpose: This file contains the manager function which handles user input for memory display and calls the loadSRecord function to load S-Records from a file into memory.
*/
#include <stdio.h>
#include "loader.h"

void manager(int argc, char *argv[]) {
    if (argc != ARG_COUNT) {
        fprintf(stderr, "Usage: %s <path_to_xme_file>\n", argv[0]);
        return;
    }

    const char *filename = argv[1];
    int start, end;
    char choice;
    char continueChoice;

    do {
        printf("Enter start address (in hex): ");
        scanf("%x", &start);

        printf("Enter end address (in hex): ");
        scanf("%x", &end);

        printf("Choose memory to display (I for IMEM, D for DMEM): ");
        scanf(" %c", &choice);

        loadSRecord(filename);

        if (choice == 'I' || choice == 'i') {
            printf("Displaying Instruction Memory (IMEM):\n\n");
            displayMemory((unsigned char *)IMEM, start, end);
            getchar();
        } else if (choice == 'D' || choice == 'd') {
            printf("Displaying Data Memory (DMEM):\n\n");
            displayMemory(DMEM, start, end);
            getchar();
        } else {
            printf("Invalid choice. Please choose 'I' for IMEM or 'D' for DMEM.\n");
            getchar();
        }

        printf("Do you want to display another range? (Y for yes, N for no): ");
        scanf(" %c", &continueChoice);
        printf("\n");
    } while (continueChoice == 'Y' || continueChoice == 'y');
}