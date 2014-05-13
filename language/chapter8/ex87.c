/*
 * exercise 8-7
 * give malloc and free
 * more error checking
 */

#include <stdlib.h>

#define MAXBYTES 1000

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

/* MAXBYTES is maintained by memcore */

void* m_malloc(unsigned int nbytes) {
    if (nbytes <= 0 || nbytes > MAXBYTES) {
        return NULL;
    }
    return malloc(nbytes);
}

void mfree(void *p) {
    Header *header;
    if (p == NULL) { 
        return;
    }

    header = (Header *)(p - 1);
    if (header->s.size > MAXBYTES) {
        return;
    }

    free(p);
}
