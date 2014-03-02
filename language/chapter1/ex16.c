/*
 * Get the value of getchar() != EOF
 *
 */

#include <stdio.h>

int main(void) {
    printf ("value of 'getchar() != EOF' is %d\n", getchar() != EOF);
    return 0;
}

/*
 * Result:
 * if input Ctrl-D (in linux), the output 0
 * otherwise output is 1
 *
 */
