/* 
 * Ex4.1
 * Write the function strindex(s,t) which returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none
 *
 */

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
    int line_len, pattern_len;

    for(line_len=0; line[line_len]!='\0'; line_len++) {
        ;
    }
    for(pattern_len=0; pattern[pattern_len]!='\0'; pattern_len++){
        ;
    }

    for(i=line_len-1; i>=0; i--) {
        for(j=i, k=pattern_len-1; j>=0&&k>=0; j--,k--) {
            if (line[j] != pattern[k]) {
                break;
            }
        }
        if(k < 0) {
            return i;
        }
    }

    return -1;
}
