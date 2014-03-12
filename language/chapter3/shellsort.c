/* shell sort */

#include <stdio.h>

void shellsort(int data[], int len);

int main(void) {
    int data[] = {1, 6, 2, 6, 3, 5, 9};
    int len = sizeof(data) / sizeof(int);
    int i;

    shellsort(data, len);
    for (i=0; i<len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

void shellsort(int data[], int len) {
    int i, j, t, gap;

    for (gap=len/2; gap>0; gap/=2) {
        /*for (i=0; i<gap; i++) {*/
        for (i=0; i<len; i++) {
            for (j=i+gap; j<len; j+=gap) {
                if (data[j] < data[j-gap]) {
                    t = data[j];
                    data[j] = data[j-gap];
                    data[j-gap] = t;
                }
            }
        }
    }
}
