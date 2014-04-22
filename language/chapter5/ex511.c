/*
 * exercise 5-11
 *
 * write a new version of entab, using parameters
 */

#define TAB_BLANK 8

int get_blank_length(int cur_line_length, \
        int blank_num_per_tab);

void print_blank_with_tab(
        int cur_line_length, \
        int cur_blanks_length, \
        int blank_num_per_tab, \
        char tab_stop);

#include <stdio.h>

int main(int argc, char *argv[]) {
    int cur_char;
    int cur_blanks_length;
    int cur_line_length;
    char tab_stop = '\t';

    cur_blanks_length = 0;
    cur_line_length = 0;

    if (argc > 1) {
        tab_stop = argv[1][0];
    }

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == ' ') {
            cur_blanks_length ++;
            cur_line_length ++;
        } else {
            if (cur_char != '\n') {
                print_blank_with_tab( \
                        cur_line_length, \
                        cur_blanks_length, \
                        TAB_BLANK, \
                        tab_stop);
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
    int cur_line_length, \
    int cur_blanks_length, \
    int blank_num_per_tab, 
    char tab_stop)
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
        first_tab_equal_blank = get_blank_length (last_non_blank_length, \
                TAB_BLANK);
        putchar (tab_stop);
        last_non_blank_length = last_non_blank_length + first_tab_equal_blank;
        while (cur_line_length - last_non_blank_length >= blank_num_per_tab) {
            putchar (tab_stop);
            last_non_blank_length += TAB_BLANK;
        }
        remain_blank = cur_line_length - last_non_blank_length;
        for (blank_index = 0; blank_index < remain_blank; blank_index ++) {
            putchar (' ');
        }
    }
}
