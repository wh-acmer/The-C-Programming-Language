#include <stdio.h>

int main(void) {
    short a = 1;
    int b = 2;
    long c = 3;
    long d = a + b + c;

    printf ("%d %d %d\n", sizeof(short), sizeof(int), sizeof(long));

    return 0;
}
