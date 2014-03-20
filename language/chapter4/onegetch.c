/* 
 * Suppose there will never be more than one character of 
 * push back, modify getch and ungetch
 */

#include <stdio.h>

char buf = EOF;

int getch(void) {
    int tbuf;

    if (buf == EOF) {
        return getchar();
    } else {
        tbuf = buf;
        buf = EOF;
        return tbuf;
    }
}


void ungetch(int cval) {
    if (buf != EOF) {
        printf("ungetch: too much ungetch.\n");
    } else {
        buf = cval;
    }
}

void ungets(char s[]);
