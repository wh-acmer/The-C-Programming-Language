/*
 * exercise 8-3
 * Design and write _flushbuf, fflush, and fclose
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "msyscall.h"

#define OPEN_MAX 20
MFILE iob[OPEN_MAX];

unsigned char flushbuf(int c, MFILE *fp) {
    int bufsize, nc;

    /* check open state */
    if ((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE) {
        return EOF;
    }

    /* set a buffer to buf the characters to be output */
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        fp->base = (char *)malloc(sizeof(char) * bufsize);
        if (fp->base == NULL) {
            return EOF;
        }
    } 

    /* buf the characters */
    nc = fp->ptr - fp->base;
    if (write(fp->fd, fp->ptr, nc) != nc) {
        fp->flag |= _ERR;
        return EOF;
    }
    fp->ptr = fp->base;
    fp->cnt = bufsize - 1;
    *fp->ptr = c;

    return *fp->ptr++;
}

int mfflush(MFILE *fp) {
    if (fp->flag & _WRITE) {
        return flushbuf(EOF, fp);
    } else {
        return 0;
    }
}

int mfclose(MFILE *fp) {
    MFILE *cur_fp;

    for(cur_fp = iob; cur_fp < iob + OPEN_MAX; cur_fp ++) {
        if (cur_fp == fp) {
            break;
        }
    }

    if (cur_fp < iob + OPEN_MAX) {
        fp->flag = 0;
        fp->cnt = 0;
        fp->ptr = NULL;
        close(fp->fd);
        fp->fd = 0;
        if (fp->base) {
            free(fp->base);
        }
        return 1;
    }
    return 0;
}
