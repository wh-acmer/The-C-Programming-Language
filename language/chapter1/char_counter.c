/*
 * Character Counting
 *
 */

#include <stdio.h>

int main(void) {
    long character_count;

    character_count = 0;
    while (getchar() != EOF) {
        character_count ++;
    }

    printf ("Count of Character is %ld.\n", character_count);

    return 0;
}
