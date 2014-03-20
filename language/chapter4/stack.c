/* stack using in calculator */

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static int sp = 0;

static double val[MAXVAL];

void push(double dval){
    if(sp < MAXVAL) {
        val[sp++] = dval;
    } else {
        printf("push:too much operands\n");
    }
}

double pop() {
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("pop:no oprands\n");
        return 0.0;
    }
}


double gettop() {
    if(sp > 0) {
        return val[sp-1];
    } else {
        printf("pop:no oprands\n");
        return 0.0;
    }
}


void duptop() {
    double top = gettop();
    push(top);
}


void swaptop() {
    double op1, op2;
    if (sp > 1) {
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
    }
}

void clear() {
    sp = 0;
}
