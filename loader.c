#include <stdio.h>
#include "loader.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_xme_file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    loadSRecord(filename);
    displayMemory();
    getchar();
    return 0;
}
