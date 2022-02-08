#include <stdio.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
wordList* appendWord(wordList *pBegin, char *word);
rowList* appendRow(rowList *pBegin, wordList *pRow);
rowList* printRows(rowList *pBegin, FILE *outputFile);
wordList* printWords(wordList *pBegin, FILE *outputFile);