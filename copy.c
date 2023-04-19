#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: copy <file1> <file2> [-v] [-f]\n");
        return 1;
    }

    char* file1 = argv[1];
    char* file2 = argv[2];
    int verbose = 0;
    int force = 0;

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            force = 1;
        }
    }

    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");

    if (fp2 != NULL && !force) {
        printf("Error: target file exists\n");
        return 1;
    }

    fp2 = fopen(file2, "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: could not open file\n");
         return 1;
    }

    int c;

    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if (verbose) {
        printf("success\n");
    }

    return 0;
}
