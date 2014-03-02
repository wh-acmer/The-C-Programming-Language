/*
 * Count digits and blank
 *
 */


#include <stdio.h>

#define DIGIT_NUM 10

int main(void) {
    long digits_count[DIGIT_NUM];
    long blank_count;
    int digit_index;
    int cur_char;

    blank_count = 0;
    for (digit_index = 0; digit_index < DIGIT_NUM; digit_index ++) {
        digits_count[digit_index] = 0;
    }

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == ' ') {
            blank_count ++;
        }

        if (cur_char >= '0' && cur_char <= '9') {
            digits_count[cur_char - '0'] ++;
        }
    }

    printf ("count of blank is %ld.\n", blank_count);
    for (digit_index = 0; digit_index < DIGIT_NUM; digit_index ++) {
        printf ("count of %d is %ld\n", \
                digit_index, digits_count[digit_index]);
    }

    return 0;
}
