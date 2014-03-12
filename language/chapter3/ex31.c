/*
 * Ex3.1
 * Our binary search makes two tests inside the loop, when one would suffice (at
 * the price of more tests outside.) Write a version with only one test inside
 * the loop and measure the difference in run-time.
 */

#include <stdio.h>

int binsearch(int x[], int n, int len);

int main(void) {
    int x[] = {1, 2, 3};
    int i, j;

    for (i=0; i<3; i++) {
        printf ("%d in pos %d\n", x[i], binsearch(x, x[i], 3));
    }

    for (j=4; j<6; j++) {
        printf ("%d in pos %d\n", j, binsearch(x, j, 3));
    }
    return 0;
}

/* May be it is not agree with the conditions in the description*/
int binsearch(int x[], int n, int len) {
    int s, t, m;

    s = 0;
    t = len - 1;

    while (s <= t) {
        m = (s + t) / 2;
        if (x[m] == n) {
            return m;
        } else {
            s = (x[m] > n) ? s: (m + 1);
            t = (x[m] > n) ? (m - 1): t;
        }
    }
    
    return -1;
}
