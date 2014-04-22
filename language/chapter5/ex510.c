/*
 * exercise 5-10
 * calculate reverse Polish expression like:
 *
 * expr 2 3 4 + *
 * evaluate 2 * (3+4)
 *
 * actually, in linux, if * is in the args, it will be
 * interprete as something else
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKLEN 1000
int stack[STACKLEN];
int top = 0;
void push(int x);
int pop(void);

int main(int argc, char *argv[]) {
    int first_operand;
    while (--argc) {
        if (isdigit((*++argv)[0]) == 0 && ((*argv)[1]) == '\0') {
            /* operator */
            switch ((*argv)[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    first_operand = pop();
                    push (pop() - first_operand);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    first_operand = pop();
                    push (pop() / first_operand);
                    break;
                default:
                    printf ("illegal operator\n");
                    break;
            }
        } else {
            /* operands */
            push(atoi(*argv));
        }
    }
    printf ("%d\n", pop());
    return 0;
}


void push(int x) {
    if (top < STACKLEN) {
        stack[top++] = x;
    } else {
        printf ("push: stack overflow\n");
    }
}

int pop(void) {
    if (top >= 0) {
        return stack[--top];
    } else {
        printf ("pop: empty stack\n");
        return -1;
    }
}
