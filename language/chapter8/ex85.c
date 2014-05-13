/*
 * exercise 8-5
 * Modifies fsize to print other information
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define S_IFMT  00170000
#define S_IFDIR  0040000

void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name) {
    struct stat stubf;

    if (stat(name, &stubf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stubf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }

    printf ("%8ld %s\n", stubf.st_size, name);
    printf ("%8ld %s\n", stubf.st_ino, name);
    printf ("%8d %s\n", stubf.st_mode, name);
    printf ("%8ld %s\n", stubf.st_atime, name);
    printf ("%8ld %s\n", stubf.st_ctime, name);
}
