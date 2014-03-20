/* 
 * ex411: modify getop to avoid ungetch
 * using static variable
 */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define UNGET_SIZE 100

int getop(char s[]) {
    int i, c;
    static int last_c = EOF;

    if (last_c != EOF) {
        c = last_c;
    }

    while((s[0] = c) == ' ' || c == '\t') {
        c = getch();
    }

    s[1] = '\0';
    if(!isdigit(c) && c !='.') {
        return c;
    }

    i = 0;
    if (isdigit(c)) {
        while(isdigit(s[++i] = c = getch()));
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if (c != EOF) {
        last_c = c;
    }
    return NUMBER;
}
