/*
 * Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by 
 * a single blank.
 */

#include <stdio.h>

int main(void) {
    int cur_char;
    int has_blank;

    has_blank = 0;
    while ((cur_char = getchar()) != EOF) {
        if (has_blank == 0 || cur_char != ' ') {
            putchar(cur_char);
        }

        if (cur_char == ' ') {
            has_blank = 1;
        } else {
            has_blank = 0;
        }
    }

    return 0;
}
