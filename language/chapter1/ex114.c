/*
 * Write a program to print a histogram of the 
 * frequencies of different characters in its input.
 *
 */

#include <stdio.h>

#define DIGITS_NUM 10
#define UPPERCASE_NUM 26
#define LOWERCASE_NUM 26

int main(void) {
    int cur_char;
    int digits_index, uppercase_index, lowercase_index;
    long digits_count[DIGITS_NUM];
    long uppercase_count[UPPERCASE_NUM];
    long lowercase_count[LOWERCASE_NUM];
    long others_count;

    for (digits_index = 0;
        digits_index < DIGITS_NUM;
        digits_index ++) {
        digits_count[digits_index] = 0;
    }

    for (uppercase_index = 0;
        uppercase_index < UPPERCASE_NUM;
        uppercase_index ++) {
        uppercase_count[uppercase_index] = 0;
    }

    for (lowercase_index = 0;
        lowercase_index < LOWERCASE_NUM;
        lowercase_index ++) {
        lowercase_count[lowercase_index] = 0;
    }

    others_count = 0;


    while ((cur_char = getchar()) != EOF) {
        if (cur_char >= '0' && cur_char <= '9') {
            digits_count[cur_char - '0'] ++;
        } else if (cur_char >= 'A' && cur_char <= 'Z') {
            uppercase_count[cur_char - 'A'] ++;
        } else if (cur_char >= 'a' && cur_char <= 'z') {
            lowercase_count[cur_char - 'a'] ++;
        } else {
            others_count ++;
        }
    }

    for (digits_index = 0;
        digits_index < DIGITS_NUM;
        digits_index ++) {
        printf ("count of %d is %ld.\n", 
                digits_index, digits_count[digits_index]);
    }

    for (uppercase_index = 0;
        uppercase_index < UPPERCASE_NUM;
        uppercase_index ++) {
        printf ("count of %c is %ld.\n",
                uppercase_index + 'A', uppercase_count[uppercase_index]);
    }

    for (lowercase_index = 0;
        lowercase_index < LOWERCASE_NUM;
        lowercase_index ++) {
        printf ("count of %c is %ld.\n",
                lowercase_index + 'a', lowercase_count[lowercase_index]);
    }

    printf ("count of others is %ld.\n", others_count);
    
    return 0;
}
