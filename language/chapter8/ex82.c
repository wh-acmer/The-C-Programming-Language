/*
 * exercise 8-2
 * Rewrite fopen and _fillbuf with fields instead of explicit
 * bit operations. Compare code size and execution speed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define PERMS 0666
#define OPEN_MAX 20

typedef struct file_state{
    unsigned int _READ : 1;
    unsigned int _WRITE : 1;
    unsigned int _UNBUF : 1;
    unsigned int _EOF : 1;
    unsigned int _ERR : 1;
}FILE_MODE;

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    FILE_MODE flag;
    int fd;
}MFILE;

MFILE iob[OPEN_MAX];

MFILE *mfopen(char *name, char *mode) {
   int fd;
   MFILE *fp;

   if (*mode != 'r' && *mode !='w' && *mode !='a') {
       return NULL;
   }

   for (fp = iob; fp < iob + OPEN_MAX; fp ++) {
       if (fp->flag._READ == 0 && fp->flag._WRITE == 0) {
           break;
       }
   }

   if (fp >= iob + OPEN_MAX) {
       return NULL;
   }

   if (*mode == 'w') {
       fd = creat(name, PERMS);
   } else if (*mode == 'a') {
       if ((fd = open(name, O_WRONLY, 0)) == -1) {
           fd = creat(name, PERMS);
       }
       lseek(fd, 0L, 2);
   } else {
       fd = open(name, O_RDONLY, 0);
   }

   if (fd == -1) {
       return NULL;
   }

   fp->fd = fd;
   fp->cnt = 0;
   fp->base = NULL;
   if (*mode == 'r') {
       fp->flag._READ = 1;
   } else {
       fp->flag._WRITE = 1;
   }
   /* DO NOT forget to initialize other flag fileds */
   fp->flag._UNBUF = 0;
   fp->flag._EOF = 0;
   fp->flag._ERR = 0;

   return fp;
}

int main(void) {
    return 0;
}
