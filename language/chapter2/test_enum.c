#include <stdio.h>

#define OK 3

int main(void) {
    enum boolean { YES };

    enum boolean x = YES;
    enum boolean y = OK;

    printf ("%d %d\n", x, y);


    return 0;
}
