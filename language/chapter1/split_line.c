/*
 * Ex1-22
 *
 * Write a program to ‘‘fold’’ long input lines into two or more 
 * shorter lines after the last non-blank character
 * that occurs before the n-th column of input. Make sure 
 * your program does something intelligent with very long lines, and if
 * there are no blanks or tabs before the specified column.
 *
 */

#include <stdio.h>

#define LINE_MAX_LEN 10

void print_blank(int blanks_len);

int main(void) {
    int cur_char;
    int cur_blanks_len;
    int cur_line_len;

    cur_blanks_len = 0;
    cur_line_len = 0;

    while ((cur_char = getchar()) != EOF) {
        cur_line_len ++;

        if (cur_char == '\n') {
            cur_line_len = 0;
            cur_blanks_len = 0;
            putchar (cur_char);
        } else if (cur_char == ' ') {
            cur_blanks_len ++;
        } else {
            if (cur_line_len > LINE_MAX_LEN) {
                putchar('\n');
                cur_blanks_len = 0;
                cur_line_len = 1;
            }
            print_blank(cur_blanks_len);
            putchar (cur_char);
            cur_blanks_len = 0;
        }
    }

    return 0;
}

void print_blank(int blanks_len) {
    while (blanks_len --) {
        putchar ('^');
    }
}
