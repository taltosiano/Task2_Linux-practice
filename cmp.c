#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: cmp <file1> <file2> [-v] [-i]\n");
        return 1;
    }

    char* file1 = argv[1];
    char* file2 = argv[2];
    int verbose = 0;
    int ignore_case = 0;

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-i") == 0) {
            ignore_case = 1;
        }
    }

    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    int equal = 1;
    int c1, c2;

    while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF) {
        if (ignore_case) {
            c1 = tolower(c1);
            c2 = tolower(c2);
        }
        if (c1 != c2) {
            equal = 0;
            break;
        }
    }

    if (equal) {
        if (verbose) {
            printf("equal\n");
        }
        return 0;
    } else {
        if (verbose) {
            printf("distinct\n");
        }
        return 1;
    }
}
