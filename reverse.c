#include "reverse.h"

// Main
int main(int argc, char *argv[]) {
    // Init variables
    FILE *inputFile;
    FILE *outputFile;
    rowList *pRows = NULL;
    wordList *pWords = NULL;
    char buffer[PATH_MAX];
    char *token;
    const char ch_return = '\n';

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
    while (fgets(buffer, PATH_MAX, inputFile) != NULL) {
        // Word by word
        token = strtok(buffer, " ");

        // Go through all words before line break
        while (token != NULL) {
            pWords = appendWord(pWords, token);
            // New line found!
            if (strchr(token, ch_return) != NULL) {
                pRows = appendRow(pRows, pWords);
                pWords = NULL;
            }
            // Add spaces removed by strtok if no newline found
            else {
                pWords = appendWord(pWords, " ");
            }
            // Next word
            token = strtok(NULL, " ");
        }
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
wordList* appendWord(wordList *pBegin, char *token) {
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
        strcpy(ptr->word, token);
        // Save address to begin of list
        pBegin = ptr;
    }
    // List already exists
    else {
        // To the end of list
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
        strcpy(ptr->word, token);
        ptr->pNext = NULL;
        // Set new slot to the end of list
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
        // Reserve memory, handle possible error
        if ((ptr = (rowList *)malloc(sizeof(wordList))) == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        // New data at the begin of the list
        ptr->pNext = pBegin;
        // Save data to reserved memory slot
        ptr->pRow = pRow;
        // Set new begin
        pBegin = ptr;
    }
    // Return address of lists begin
    return pBegin;
}

// Print & Delete rowList
rowList* printRows(rowList *pBegin, FILE *outputFile) {
    rowList *ptr = pBegin;
    while (pBegin != NULL) {
        pBegin = ptr->pNext;
        if (printWords(ptr->pRow, outputFile) != NULL) {
            fprintf(stderr, "Error while printing row!\n");
        }
        free(ptr);
        ptr = pBegin;
    }
    return pBegin;
}

// Print & Delete wordList
wordList* printWords(wordList *pBegin, FILE *outputFile) {
    wordList *ptr = pBegin;
    while (pBegin != NULL) {
        pBegin = ptr->pNext;
        fprintf(outputFile, ptr->word);
        //fprintf(stdout, ptr->word);
        free(ptr);
        ptr = pBegin;
    }
    return pBegin;
}