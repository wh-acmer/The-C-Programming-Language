/*
 * exercise 7-3
 *
 * Revise minprintf to handle more of the other 
 * facilities of printf.
 *
 */

#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(void) {
    minprintf("i:%d, j:%f, k:%s\n", 1, 2.1, "test");
    minprintf("i:%x, j:%e\n", 18, 2.1);
    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'i': /* same as 'd' */
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'x': /* same as 'X' */
            case 'X':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'e': /* same as 'E' */
            case 'E':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
}
