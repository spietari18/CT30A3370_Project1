#include <stdio.h>

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
char * readFile(char fileName[]);
void writeFile(char fileName[], rowList *firstRow);