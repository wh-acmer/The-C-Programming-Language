/*
 * Words Counting
 *
 */

#include <stdio.h>

#define OUT 0
#define IN 1

int main(void) {
    int cur_char;
    int state;
    long words_count;

    state = OUT;
    words_count = 0;

    while ((cur_char = getchar()) != EOF) {
        if (state == OUT) {
            if (cur_char != '\t' \
                && cur_char != '\n' \
                && cur_char != ' ') {

                words_count ++;
                state = IN;
            }
        }

        if (state == IN) {
            if (cur_char == '\t' \
                || cur_char == '\n' \
                || cur_char == ' ') {

                state = OUT;
            }
        }
    }

    printf ("Count of words is %ld.\n", words_count);

    return 0;
}
