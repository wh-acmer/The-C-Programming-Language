/*
 * Excercise 1-2
 *
 */

#include <stdio.h>

int main(void) {
    printf ("hello\c, world\n");
    return 0;
}

/*
 * Result after compile:
 *
 * ex12.c: In function ‘main’:
 * ex12.c:9:13: warning: unknown escape sequence: '\c' [enabled by default]
 * 
 * Result after run:
 *
 * helloc, world
 *
 */
