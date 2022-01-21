#include "reverse.h"

// Main
int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>");
    }
    else if (argc == 3) {
        if ((inputFile = fopen(argv[1], "r")) == NULL) {
            fileError(argv[1]);
        }
        if ((inputFile = fopen(argv[2], "w")) == NULL) {
            fileError(argv[2]);
        }
    }
    else if (argc == 2) {
        if ((inputFile = fopen(argv[1], "r")) == NULL) {
            fileError(argv[1]);
        }
        outputFile = stdout;
    }
    else if (argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
    }
    else {
        fprintf(stderr, "This error shouldn't happen!");
        exit(1);
    }
}

// Print file open error and exit
void fileError(char fileName[PATH_MAX]) {
    fprintf(stderr, "error: cannot open file '%s'", fileName);
    exit(1);
}

// Read file
rowList* readFile(FILE *inputFile) {
    //TODO
    rowList result;
    return &result;
}

// Write file
void writeFile(FILE *outputFile, rowList *firstRow) {
    //TODO
    exit(0);
}
