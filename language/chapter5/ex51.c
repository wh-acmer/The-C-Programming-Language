/* 
 * exercise 5-1
 * fix '+ non-digit' makes 0 
 * in getint
 */

/* getint: get integer from input */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(void) {
    int n;

    while(getint(&n) != EOF) {
        printf ("%d\n", n);
    }
    return 0;
}

int getint(int *pn) {
    int c, sign;

    /* skip blank */
    while(isspace(c=getch())) {
        ;
    }

    /* if it is not a number */
    if(isdigit(c) == 0 && \
       c != EOF && \
       c != '+' && \
       c != '-') {
        ungetch(c);
        return 0;
    }

    /* get sign */
    sign = (c == '-') ? -1 : 1;

    /* skip sign */
    if (c == '+' || c == '-') {
        c = getch();
    }

    /* check invalid '[+-] [^0-9] */
    if (isdigit(c) == 0) {
        ungetch(c);
        return 0;
    }

    /* read integer */
    *pn = 0;
    while (isdigit(c)) {
        *pn = *pn * 10 + c - '0';
        c = getch();
    }

    /* apply sign */
    *pn = sign * *pn;

    /* unget the last input character */
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}
