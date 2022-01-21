#include "reverse.h"

// Main
int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>");
    }
    else if (argc == 3) {
        if (argv[1] == argv[2]) {
            fprintf(stderr, "Input and output file must differ");
            exit(1);
        }
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

// Append to wordList
wordList* appendWord(wordList *pBegin, char word[PATH_MAX]) {
    // Create a temporary pointer for memory to be reserved
    wordList *ptr = NULL;
    // If list doesn't exist
    if (pBegin == NULL) {
        // Reserve memory, handle possible error
        if ((ptr = (wordList *)malloc(sizeof(wordList))) == NULL) {
            fprintf("malloc failed");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        strcpy(ptr->word, word);
        // Save address to begin of list
        pBegin = ptr;
    }
    // List already exists
    else {
        // Loop through the list to the end
        wordList *slider = pBegin;
        while (slider->pNext != NULL) {
            slider = slider->pNext;
        }
        // Reserve memory, handle possible error
        if ((ptr = (wordList *)malloc(sizeof(wordList))) == NULL) {
            fprintf("malloc failed");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        strcpy(ptr->word, word);
        // Save address to the end of list
        slider->pNext = ptr;
    }
    // Return address of lists begin
    return pBegin;
}

// Append to rowList
rowList* appendRow(rowList *pBegin, wordList *pRow) {
    // Create a temporary pointer for memory to be reserved
    rowList *ptr = NULL;
    // If list doesn't exist
    if (pBegin == NULL) {
        // Reserve memory, handle possible error
        if ((ptr = (rowList *)malloc(sizeof(rowList))) == NULL) {
            fprintf("malloc failed");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        strcpy(ptr->pRow, pRow);
        // Save address to begin of list
        pBegin = ptr;
    }
    // List already exists
    else {
        // Loop through the list to the end
        rowList *slider = pBegin;
        while (slider->pNext != NULL) {
            slider = slider->pNext;
        }
        // Reserve memory, handle possible error
        if ((ptr = (rowList *)malloc(sizeof(rowList))) == NULL) {
            fprintf("malloc failed");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        strcpy(ptr->pRow, pRow);
        // Save address to the end of list
        slider->pNext = ptr;
    }
    // Return address of lists begin
    return pBegin;
}

// Print & Delete rowList
rowList* printRows(rowList *pBegin) {
    rowList *ptr = pBegin;
    rowList *slider = pBegin;
    while (ptr != NULL) {
        while (slider->pNext != NULL) {
            slider = slider->pNext;
        }
        if(!(printWords(slider) == NULL)) {
            fprintf(stderr, "Error while removing row from a list");
        }
        slider = pBegin;
    }
}

// Print & Delete wordList
wordList* printWords(wordList *pBegin) {
    wordList *ptr = pBegin;
    wordList *slider = pBegin;
    while (ptr->pNext != NULL) {

    }
}