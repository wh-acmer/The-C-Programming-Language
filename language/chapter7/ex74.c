/*
 * exercise 7-4
 * write a private version of scanf analogous to 
 * minprintf from the previous section.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

int minscanf(char *fmt, ...);

int main(void) {
    int a;
    double b;

    minscanf("%d %f", &a, &b);
    printf("%d,%f", a, b);
    return 0;
}

int minscanf(char *fmt, ...) {
    va_list ap;
    char *p;
    int *ival;
    double *dval;
    int c;
    int read_num = 0;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p == ' ' || *p == '\t') {
            continue;
        }
        if (*p != '%') {
            c = va_arg(ap, int);
            if (c != *p) {
                return read_num;
            }
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                read_num ++;
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf("%lf", dval);
                read_num ++;
                break;
            default:
                break;
        }
    }

    va_end(ap);
    return read_num;
}
