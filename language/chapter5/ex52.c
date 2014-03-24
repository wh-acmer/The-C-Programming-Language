/* 
 * exercise 5-2
 * getfloat
 *
 */

/* getfloat: get a float number from input */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getfloat(float *pf);

int main(void) {
    float f;

    while(getfloat(&f) != EOF) {
        printf ("%f\n", f);
    }
    return 0;
}

int getfloat(float *pf) {
    int c, sign, times;

    /* skip space */
    while (isspace(c=getch())) {
        ;
    }

    /* 
     * it is not a number 
     * the following program will not
     * process these inputs
     */
    if (isdigit(c) == 0 && \
        c != EOF &&
        c != '+' &&
        c != '-' &&
        c != '.') {
        ungetch(c);
        return c;
    }

    /* check sign */
    sign = (c == '-') ? -1: 1;

    /* skip sign */
    if (c == '+' || c == '-') {
        c = getch();
    }

    /* get input float number */
    *pf = 0.0;
    /* get integer part */
    while (isdigit(c)) {
        *pf = *pf * 10 + c - '0';
        c = getch();
    }
    /* get fractional part */
    times = 1;
    if (c == '.') {
        while(isdigit(c=getch())) {
            *pf = *pf * 10 + c - '0';
            times *= 10;
        }
    }
    *pf /= times;
    *pf *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}
