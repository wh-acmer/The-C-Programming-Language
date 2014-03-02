/*
 * Print histogram of length of words
 *
 */

#include <stdio.h>

int main(void) {
    int cur_char;
    int cur_word_length;
    int histogram_index;
    int histogram_char;

    cur_word_length = 0;
    histogram_char = '*';

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == ' ' 
            || cur_char == '\n'
            || cur_char == '\t') {
            for (histogram_index = 0; 
                histogram_index < cur_word_length; 
                histogram_index ++) {
                putchar (histogram_char);
            }
            putchar ('\n');

            cur_word_length = 0;
        } else {
            cur_word_length ++;
        }
    }

    return 0;
}
