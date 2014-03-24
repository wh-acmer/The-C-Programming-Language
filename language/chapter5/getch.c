/* get and unget character from input */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];

int bufp = 0;

int getch(void) {
    if (bufp == 0) {
        return getchar();
    } else {
        return buf[--bufp];
    }
}

void ungetch(int cval) {
    if (bufp < BUFSIZE) {
        if (buf==0 || buf[bufp-1] != EOF) {
            buf[bufp++] = cval;
        }
    } else {
        printf("ungetch:too much characters\n");
    }
}

void ungets(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    while (i!=0 && s[--i]) {
        ungetch(s[i]);
    }
}
