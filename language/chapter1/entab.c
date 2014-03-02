/*
 * Ex1-21
 *
 * Write a program entab that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same 
 * tab stops as for detab. When either a tab or a single blank would
 * suffice to reach a tab stop, which should be given preference?
 *
 */


/*
 * Does name of the variable too long to improve readability?
 *
 */

#define TAB_BLANK 8

int get_blank_length(int cur_line_length, int blank_num_per_tab);
void print_blank_with_tab(int cur_line_length, int cur_blanks_length, int blank_num_per_tab);

#include <stdio.h>

int main(void) {
    int cur_char;
    int cur_blanks_length;
    int cur_line_length;

    cur_blanks_length = 0;
    cur_line_length = 0;

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == ' ') {
            cur_blanks_length ++;
            cur_line_length ++;
        } else {
            if (cur_char != '\n') {
                print_blank_with_tab(cur_line_length, cur_blanks_length, TAB_BLANK);
            } else {
                cur_line_length = 0;
            }
            putchar (cur_char);
            cur_blanks_length = 0;
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

void print_blank_with_tab(
    int cur_line_length, int cur_blanks_length, int blank_num_per_tab) 
{
    int remain_blank;
    int blank_index;
    int last_non_blank_length;
    int first_tab_equal_blank;

    if (cur_blanks_length < blank_num_per_tab) {
        for (blank_index = 0; blank_index < cur_blanks_length; blank_index ++) {
            putchar (' ');
        }
    } else {
        last_non_blank_length = cur_line_length - cur_blanks_length;
        first_tab_equal_blank = get_blank_length (last_non_blank_length, TAB_BLANK);
        putchar ('\t');
        last_non_blank_length = last_non_blank_length + first_tab_equal_blank;
        while (cur_line_length - last_non_blank_length >= blank_num_per_tab) {
            putchar ('\t');
            last_non_blank_length += TAB_BLANK;
        }
        remain_blank = cur_line_length - last_non_blank_length;
        for (blank_index = 0; blank_index < remain_blank; blank_index ++) {
            putchar (' ');
        }
    }
}
