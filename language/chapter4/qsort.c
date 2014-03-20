/* demo of quick sort */

#include <stdio.h>

void mqsort(int data[], int start, int end);
void print_array(int data[], int len);
void swap(int data[], int s, int t);

int main(void) {
    /* int data[] = {3, 1, 4, 6, 2, 4, 0}; */
    /* int data[] = {2}; */
    /* int data[] = {1, 2}; */
    /* int data[] = {1, 2, 3}; */
    int data[] = {1, 2, 3};
    int len = sizeof(data) / sizeof(int);


    print_array(data, len);
    mqsort(data, 0, len-1);
    print_array(data, len);

    return 0;
}

void mqsort(int data[], int start, int end) {
    int mid, i, j;

    if (start >= end) {
        return;
    }

    mid = data[start];
    i = start;
    j = end;

    while (i <= j) {
        while(i<=j && data[i] <= mid) {
            i++;
        }
        while(i<=j && data[j] > mid) {
            j--;
        }
        if(i<=j && data[i]>mid && data[j] <= mid) {
            swap(data, i, j);
        }
    }

    swap(data, start, i-1);
    mqsort(data, start, i-2);
    mqsort(data, i, end);
}

void print_array(int data[], int len) {
    int i = 0;
    for (i=0; i<len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void swap(int data[], int s, int t) {
    int tmp;

    tmp = data[s];
    data[s] = data[t];
    data[t] = tmp;
}
