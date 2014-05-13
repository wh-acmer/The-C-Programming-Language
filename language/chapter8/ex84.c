/* 
 * exercise 8-4
 * int fseek(FILE *fp, long offset, int origin)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "msyscall.h"

int mfflush(MFILE *fp);

int feek(MFILE *fp, long offset, int origin) {
    int true_offset = offset;
    if ((fp->flag & (_READ | _EOF | _ERR)) == _READ) {
        if (origin == 1) {
            true_offset = offset - fp->cnt;
        } 
        fp->cnt = 0;
        fp->ptr = fp->base;
    } else if ((fp->flag & (_WRITE | _EOF | _ERR)) == _WRITE) {
        mfflush(fp);
    } else {
       return -1;
    } 

    return lseek(fp->fd, true_offset, origin);
}
