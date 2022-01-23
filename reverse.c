#include "reverse.h"

// Main
int main(int argc, char *argv[]) {
    // Init variables
    FILE *inputFile;
    FILE *outputFile;
    rowList *pRows = NULL;
    wordList *pWords = NULL;
    char cache[PATH_MAX];
    char *newLine;

    // Handle arguments, set input & output files
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
    }
    else if (argc == 3) {
        if (argv[1] == argv[2]) {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        if ((inputFile = fopen(argv[1], "r")) == NULL) {
            fileError(argv[1]);
        }
        if ((outputFile = fopen(argv[2], "w")) == NULL) {
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
        fprintf(stderr, "This error shouldn't happen!\n");
        exit(1);
    }

    // Read input, save to lists
    while (fgets(cache, PATH_MAX, inputFile) != NULL) {
        // Word by word
        strcpy(cache, strtok(cache, " "));
        pWords = appendWord(pWords, cache);
        // If contains newline
        newLine = strstr(cache, "\n");
        if (newLine) {
            pRows = appendRow(pRows, pWords);
            pWords = NULL;
        }
    }
    if (pWords != NULL) {
        pRows = appendRow(pRows, pWords);
    }

    // Print reversed, delete lists
    if ((pRows = printRows(pRows, outputFile)) == NULL) {
        fclose(inputFile);
        fclose(outputFile);
        exit(0);
    } else {
        fprintf(stderr, "Memory release failed!\n");
        exit(1);
    }
}

// Print file open error and exit
void fileError(char fileName[PATH_MAX]) {
    fprintf(stderr, "error: cannot open file '%s'\n", fileName);
    exit(1);
}

// Append to wordList
wordList* appendWord(wordList *pBegin, char word[PATH_MAX]) {
    // Create a temporary pointer for memory to be reserved
    wordList *ptr = NULL;
    // If list doesn't exist
    if (pBegin == NULL) {
        // Reserve memory, handle possible error
        if ((ptr = (wordList *)malloc(sizeof(wordList))) == NULL) {
            fprintf(stderr, "malloc failed\n");
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
            fprintf(stderr, "malloc failed\n");
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
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        ptr->pRow = pRow;
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
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        // Save data to reserved memory slot
        ptr->pNext = NULL;
        ptr->pRow = pRow;
        // Save address to the end of list
        slider->pNext = ptr;
    }
    // Return address of lists begin
    return pBegin;
}

// Print & Delete rowList
rowList* printRows(rowList *pBegin, FILE *outputFile) {
    rowList *slider = pBegin;
    while (true) {
        while (slider->pNext != NULL) {
            slider = slider->pNext;
        }
        if (slider == pBegin) {
            if(printWords(slider->pRow, outputFile) != NULL) {
                fprintf(stderr, "Error while removing the last row from a list\n");
            }
            free(pBegin);
            break;
        }
        if((printWords(slider->pRow, outputFile)) != NULL) {
            fprintf(stderr, "Error while removing a row from a list\n");
        }
        free(slider);
        slider = pBegin;
    }
    return pBegin;
}

// Print & Delete wordList
wordList* printWords(wordList *pBegin, FILE *outputFile) {
    wordList *slider = pBegin;
    while (true) {
        while (slider->pNext != NULL) {
            slider = slider->pNext;
        }
        if (slider == pBegin) {
            fprintf(outputFile, pBegin->word);
            fprintf(stdout, pBegin->word);
            free(pBegin);
            break;
        }
        fprintf(outputFile, slider->word);
        fprintf(stdout, slider->word);
        free(slider);
        slider = pBegin;
    }
    return pBegin;
}