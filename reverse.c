#include "reverse.h"

// Main
int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>");
    }
    else if (argc == 3) {
        inputFile = openFile(inputFile, argv[1], "r");
        outputFile = openFile(outputFile, argv[2], "w");
    }
    else if (argc == 2) {
        inputFile = openFile(inputFile, argv[1], "r");
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

// Open file
FILE* openFile(FILE *file, char fileName[PATH_MAX], char rw) {
    if ((file == fopen(fileName, rw)) == NULL) {
        fprintf(stderr, "error: cannot open file '%s'", fileName);
        exit(1);
    }
    return file;
}

// Read file
rowList* readFile(FILE *inputFile) {
    rowList result;
    return result;
}

// Write file
void writeFile(FILE *outputFile, rowList *firstRow) {
    exit(0);
}
