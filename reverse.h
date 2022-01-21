#include <stdio.h>
#include <linux/limits.h>
#include <stdlib.h>

// Define list structures
struct oneRow {
    struct oneRow *pNext;
    char word[PATH_MAX];
};
typedef struct oneRow wordList;

struct fileRows {
    struct fileRows *pNext;
    struct oneRow *pRow;
};
typedef struct fileRows rowList;

int main(int argc, char *argv[]);
void fileError(char fileName[PATH_MAX]);
rowList* readFile(FILE *inputFile);
void writeFile(FILE *outputFile, rowList *firstRow);
wordList* appendWord(wordList *pBegin, char word[PATH_MAX]);
rowList* appendRow(rowList *pBegin, wordList *pRow);
