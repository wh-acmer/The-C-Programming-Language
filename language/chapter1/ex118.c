/*
 * ex1-18
 * Write a program to remove trailing blanks and 
 * tabs from each line of input, and to delete entirely blank lines.
 * 
 */

#include <stdio.h>

int main(void) {
    int cur_char;
    int blank_num, tab_num;
    int blank_index, tab_index;

    blank_num = 0;
    tab_num = 0;

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == ' ') {
            blank_num = blank_num + 1;
        } else if (cur_char == '\t') {
            tab_num = tab_num + 1;
        } else {
            if (cur_char != '\n') {
                for (blank_index = 0; blank_index < blank_num; blank_index ++) {
                    putchar (' ');
                }
                for (tab_index = 0; tab_index < tab_num; tab_index ++) {
                    putchar ('\t');
                }
                putchar (cur_char);
            } else {
                printf ("\\n");
                printf ("\n");
            }
            blank_num = 0;
            tab_num = 0;
        }
    }
    return 0;
}
