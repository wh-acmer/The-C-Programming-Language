/*
 * exercise 8-8
 * bfree(p, n)
 * free an arbitrary block p of n characters into the free
 * list maintained by malloc and free. By using bfree, a user
 * can add a static or external array to thre free list at any
 * time
 */
#include <stdio.h>
#include <stdlib.h>

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

int bfree(void *ap, int n) {
    /*
    bp = (Header *)ap;
    bp->s.size = n;
    bp->s.ptr = freep->s.ptr;
    freep->s.ptr = bp;
    */

    Header *bp;
    int tn;

    if (n < sizeof(Header)) {
        return 0;
    }

    /* tn = n / sizeof(Header) + 1; */
    tn = n / sizeof(Header) + 1;
    bp = (Header *)ap;
    bp->s.size = tn;
    free((void*)(bp + 1));

    return bp->s.size;
}
