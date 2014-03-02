/*
 * Character Counting
 *
 */

#include <stdio.h>

int main(void) {
    long character_count;

    for (character_count = 0; getchar() != EOF; character_count ++) {
        ;
    }

    printf ("Count of Character is %ld.\n", character_count);

    return 0;
}
