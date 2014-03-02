/*
 * Lines Counting
 *
 */

#include <stdio.h>

int main(void) {
    long line_count;
    int cur_char;

    line_count = 0;
    while ((cur_char = getchar()) != EOF) {
        if (cur_char == '\n') {
            line_count ++;
        }
    }

    printf ("Count of lines is: %ld\n", line_count);

    return 0;
}
