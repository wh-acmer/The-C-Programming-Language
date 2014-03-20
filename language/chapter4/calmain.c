/* calculator main file */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main(void) {
    int type, lasttype;
    double op1;
    char str[MAXOP];

    lasttype = LAST;
    while ((type=getop(str)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(str));
                break;
            case VAR:
                push(getvar(str[0] - 'a'));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op1 = pop();
                push(pop() - op1);
                break;
            case '/':
                op1 = pop();
                if (op1 != 0) {
                    push(pop() / op1);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op1 = pop();
                if (op1 != 0) {
                    push(((int)pop()) % ((int)op1));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                op1 = pop();
                if (lasttype != VAR) {
                    setvar(op1);
                }
                printf ("%lf\n", op1);
                break;
            case POW:
                op1 = pop();
                push(pow(pop(), op1));
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            default:
                printf ("action parse error\n");
                break;
        }
        lasttype = type;
    }
    return 0;
}
