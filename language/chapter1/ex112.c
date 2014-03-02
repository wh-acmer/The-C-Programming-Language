/*
 * Print input, one word one line
 *
 */

#include <stdio.h>

#define OUT 0
#define IN 1

int main(void) {
    int cur_char;
    int state;

    state = OUT;

    while ((cur_char = getchar()) != EOF) {
        putchar (cur_char);

        if (cur_char == '\t' \
            || cur_char == '\n' \
            || cur_char == ' ') {
            if (state == IN) {
                putchar ('\n');
            }
            state = OUT;
        } else {
            state = IN;
        }
    }

    return 0;
}
