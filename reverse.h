#include <stdio.h>
#include <linux/limits.h>

// Define list structures
struct oneRow {
    struct oneRow *pNext;
    char word[PATH_MAX];
};
typedef struct oneRow wordList;

struct fileRows {
    struct fileRows *pNext;
    struct oneRow row;
};
typedef struct fileRows rowList;

int main(int argc, char *argv[]);
FILE* openFile(char fileName[PATH_MAX], char rw)
rowList* readFile(FILE *inputFile);
void writeFile(FILE *outputFile, rowList *firstRow);