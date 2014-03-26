/*
 * exercise 5-7
 * rewrite readlines to store lines in an array supplied
 * by main rather than calling alloc to maintain storage
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define LINELEN 1000

int readlines(char lines[][LINELEN], int maxlen);
void writelines(char lines[][LINELEN], int line_len);
int getline(char *line, int maxlen);

int main(void) {
    char lines[MAXLINES][LINELEN];
    int nlines;

    if ((nlines = readlines(lines, MAXLINES)) >= 0) {
        writelines(lines, nlines);
    } else {
        printf("Too much lines.\n");
    }
    return 0;
}


int readlines(char lines[][LINELEN], int maxlen) {
    int len, nlines;
    char line[LINELEN];
    nlines = 0;
    while ((len = getline(line, LINELEN)) > 0) {
        if (nlines < maxlen) {
            line[len-1] = '\0';
            strncpy(lines[nlines], line, len);
            nlines ++;
        } else {
            return -1;
        }
    }
    return nlines;
}

void writelines(char lines[][LINELEN], int line_len) {
    int i;

    for (i=0; i<line_len; i++) {
        printf ("%s\n", lines[i]);
    }
}

int getline(char *line, int maxlen) {
    int c, i;

    for (i=0; i < maxlen-2 && (c=getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (i == 0) {
        return 0;
    } else {
        line[i+1] = '\n';
        line[i+2] = '\0';
        return i+3;
    }
}
