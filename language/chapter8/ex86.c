/*
 * exercise 8-6
 * write calloc(n, size)
 * returns a pointer to n object of size, with the 
 * storage initialized to zero
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mcalloc(int n, int size) {
    int s = n * size;
    void *p = malloc(s);
    memset(p, s, 0);
    return p;
}
