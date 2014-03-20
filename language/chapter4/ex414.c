/*
 * ex4.14 
 * Defing a macro swap(t, x, y)
 */

#include <stdio.h>

#define SWAP(t, x, y) { \
    t k; \
    k = x; \
    x = y; \
    y = k; \
}

int main(void) {
    int a = 1, b = 2;
    float c = 3.0, d = 4.0;

    printf ("%d %d\n", a, b);
    printf ("%f %f\n", c, d);

    SWAP(int, a, b)
    SWAP(float, c, d)

    printf ("%d %d\n", a, b);
    printf ("%f %f\n", c, d);

    return 0;
}
