/*
 * Blanks, Tabs, Nextlines Counting
 *
 */

#include <stdio.h>

int main(void) {
    long line_count, blank_count, tab_count;
    int cur_char;

    line_count = 0;
    blank_count = 0;
    tab_count = 0;
    while ((cur_char = getchar()) != EOF) {
        if (cur_char == '\n') {
            line_count ++;
        }
        if (cur_char == ' ') {
            blank_count ++;
        }
        if (cur_char == '\t') {
            tab_count ++;
        }

    }

    printf ("Count of lines is: %ld\n", line_count);
    printf ("Count of blanks is: %ld\n", blank_count);
    printf ("Count of tabs is: %ld\n", tab_count);

    return 0;
}
