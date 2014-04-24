/*
 * exercise 7-8
 * print a set of files,
 * each one in a new page,
 * with title, page count,
 */

#include <stdio.h>
#include <stdlib.h>

#define PAGELINES 20
#define LINELEN 100

int output_file(char *fpath) {
    FILE *fp = fopen(fpath, "r");
    char line[LINELEN + 1];
    int line_num = 0;

    if (fp == NULL) {
        return 1;
    } 

    while (fgets(line, LINELEN, fp) != NULL) {
        printf("%s", line);
        line_num ++;
        if (line_num == PAGELINES) {
            line_num = 0;
        }
    }

    while (line_num > 0 && line_num < PAGELINES) {
        printf("\n");
        line_num ++;
    }

    
    return 0;
}

int main(int argc, char **argv) {
    char *prog = argv[0];
    char *cur_f;
    int i, page_count;
    if (argc < 1) {
        fprintf(stderr, "%s file1 file2 ...\n", prog);
        exit(1);
    }

    i = 1;
    page_count = 1;
    while (i < argc) {
        cur_f = argv[i++];
        printf("file:%s page:%d\n", cur_f, page_count++);
        output_file(cur_f);
    }

    exit(0);
}
