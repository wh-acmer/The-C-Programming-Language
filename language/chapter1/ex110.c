/*
 * replace tab with '\t', backslash with '\\'
 *
 */

#include <stdio.h>

int main(void) {
    int cur_char;

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == '\t') {
            printf("\\t");
        } else if (cur_char == '\\') {
            printf("\\\\");
        } else {
            putchar(cur_char);
        }
    }

    return 0;
}
