
/* 
 * exercise 7-6 
 * write a program to compare two files,
 * print the first difference line
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 100

int compare_files(char *f1, char *f2);

int main(int argc, char **argv) {
    char *prog = argv[0];

    if (argc < 2) {
        fprintf(stderr, "%s: file1, file2\n", prog);
        exit(1);
    }

    if (compare_files(argv[1], argv[2]) != 0) {
        exit(2);
    }

    exit(0);
}

int compare_files(char *f1, char *f2) {
    FILE *fp1, *fp2;
    char line1[LINELEN + 1], line2[LINELEN + 1];
    int line_num;

    fp1 = fopen(f1, "r");
    fp2 = fopen(f2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        return 1;
    }

    line_num = 1;
    while (fgets(line1, LINELEN, fp1) && fgets(line2, LINELEN, fp2)) {
        if (strncmp(line1, line2, LINELEN) != 0) {
            printf("%dc%d\n", line_num, line_num);
            printf("< %s", line1);
            printf("---\n");
            printf("> %s", line2);
            break;
        }
        line_num ++;
    }

    return 0;
}
