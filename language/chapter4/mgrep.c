/* Find a pattern in lines */

#include <stdio.h>

#define LEN 200

int getline(char line[], int len);
int strindex(char line[], char patter[]);

int main(void) {
    char line[LEN];
    char pattern[LEN] = "is";

    while (getline(line, LEN) != 0) {
        if (strindex(line, pattern) != -1) {
            printf ("%s", line);
        }
    }
    return 0;
}


int getline(char line[], int len) {
    int c, i, cur_len;

    i = 0;
    while(i<len && (c=getchar()) != EOF) {
        line[i++] = c;
        if (c == '\n') {
            break;
        }
    }
    line[i] = '\0';
    cur_len = i;

    return cur_len;
}

int strindex(char line[], char pattern[]) {
    int i, j, k;

    for(i=0; line[i]!='\0'; i++) {
        for (j=i, k=0; line[j]!='\0' && pattern[k]!='\0'; j++, k++) {
            if (line[j] != pattern[k]) {
                break;
            }
        }
        if (pattern[k] == '\0') {
            return i;
        }
    }

    return -1;
}
