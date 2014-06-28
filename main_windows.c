#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int getNextClosingBracket(char* code, int programmPointer, long length) {
    int n = programmPointer;

    while(n < length) {
        if (code[n] == ']') {
            return n;
        } else {
            n++;
        }
    }
    return -1;
}

int runCode(char* code, long length) {
    int initialCount = 10;

    int  cellCount = initialCount;
    int* cells = (int *) malloc(cellCount * sizeof(int));
    int  cellPointer = 0;

    int  bracketStackCount = initialCount;
    int* bracketStack = (int *) malloc(bracketStackCount * sizeof(int));
    int  bracketStackPointer = 0;

    int i;
    for (i = 0; i < initialCount; i++) {
        cells[i] = 0;
        bracketStack[i] = 0;
    }

    int programmPointer = 0;

    while(programmPointer < length) {
        char token = code[programmPointer];
        switch(token) {
            case '>':
                if (++cellPointer + 1 > cellCount) {
                    cells = (int *) realloc(cells, ++cellCount * sizeof(int));
                    cells[cellPointer] = 0;
                }

                programmPointer++;
                break;
            case '<':
                if (--cellPointer < 0) {
                    printf("\n\nERROR: You can't decrease the cell pointer lower than 0 at char %i.", programmPointer);
                    goto end;
                }

                programmPointer++;
                break;
            case '+':
                cells[cellPointer]++;
                programmPointer++;
                break;
            case '-':
                cells[cellPointer]--;
                programmPointer++;
                break;
            case '.':
                printf("%c", cells[cellPointer]);
                programmPointer++;
                break;
            case ',':
                cells[cellPointer] = getch();
                programmPointer++;
                break;
            case '[':
                if (cells[cellPointer] == 0) {
                    programmPointer = getNextClosingBracket(code, programmPointer, length) + 1;
                } else {
                    if (++bracketStackPointer > bracketStackCount) {
                        bracketStack = (int *) realloc(bracketStack, ++bracketStackCount * sizeof(int));
                    }

                    bracketStack[bracketStackPointer - 1] = programmPointer;
                    programmPointer++;
                }
                break;
            case ']':
                if (cells[cellPointer] == 0) {
                    if (--bracketStackPointer < 0) {
                        printf("\n\nERROR: There is no opening bracket for closing bracket at char %i.", programmPointer);
                        goto end;
                    }

                    programmPointer++;
                } else {
                    if (bracketStackPointer < 1) {
                        printf("\n\nERROR: There is no opening bracket for closing bracket at char %i.", programmPointer);
                        goto end;
                    }

                    programmPointer = bracketStack[bracketStackPointer - 1] + 1;
                }
                break;
            default:
                programmPointer++;
                break;
        }
    }

    printf("\n\nPress any key to continue.");
    getch();

    end:

    free(code);
    free(cells);
    free(bracketStack);

    return 0;
}

int main(int argc, const char** argv)
{
    if (argc < 2) {
        printf("You have to give the brainfuck interpreter a name of a file that contains brainfuck code.");
        return 1;
    }
    char* fileName = argv[1];

    char* code = 0;
    long length;
    FILE * file = fopen (fileName, "rb");

    if (file)
    {
      fseek (file, 0, SEEK_END);
      length = ftell (file);
      fseek (file, 0, SEEK_SET);
      code = malloc (length);
      if (code)
      {
        fread (code, 1, length, file);
      }
      fclose (file);
    }

    if (code)
    {
        return runCode(code, length);
    }

    return 1;
}
