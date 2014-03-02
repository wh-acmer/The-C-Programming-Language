/*
 * Ex1-20
 *
 * Write a program detab that replaces tabs in the input with 
 * the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tab stops, say every 
 * n columns. Should n be a variable or a symbolic parameter?
 *
 */

/* evey TAB_BLANK has a tab stops*/
#define TAB_BLANK 4

#include <stdio.h>

int get_blank_length(int cur_line_length, int blank_num_per_tab);

int main(void) {
    int cur_char;
    int cur_line_length;
    int cur_blank_length;
    int blank_index;

    cur_line_length = 0;
    while ((cur_char = getchar()) != EOF) {
        if (cur_char == '\n') {
            cur_line_length = 0;
        } else if (cur_char == '\t') {
            cur_blank_length = get_blank_length(cur_line_length, TAB_BLANK);
            for (blank_index = 0; blank_index < cur_blank_length; blank_index ++) {
                putchar ('^'); /* use '^' to represent blank */
            }
            cur_line_length += cur_blank_length;
        } else {
            cur_line_length += 1;
        }

        if (cur_char != '\t') {
            putchar (cur_char);
        }
    }

    return 0;
}


int get_blank_length(int cur_line_length, int blank_num_per_tab) {
    int tab_num;
    int blank_remain, blank_need;

    tab_num = cur_line_length / blank_num_per_tab;
    blank_remain = cur_line_length - tab_num * blank_num_per_tab;
    blank_need = blank_num_per_tab - blank_remain;

    return blank_need;
}
