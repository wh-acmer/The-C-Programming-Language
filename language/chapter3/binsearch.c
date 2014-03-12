/* Binary Search a sorted sequence */

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


int binsearch(int x[], int n, int len) {
    int s, t, m;

    s = 0;
    t = len - 1;

    while (s <= t) {
        m = (s + t) / 2;
        if (x[m] == n) {
            return m;
        } else if (x[m] > n) {
            t = m - 1;
        } else if (x[m] < n) {
            s = m + 1;
        } else {
            /* impossible */
        }
    }
    
    return -1;
}
