/*
 * ex1-17 
 * Write a program to print all input lines that are longer than 4 characters
 *
 */

#include <stdio.h>

#define LINE_MAX_LEN 100
#define LIMIT 4

int getline(char cur_line[LINE_MAX_LEN], int max_len);

int main(void) {
    int cur_length;
    int total_length;
    char cur_line[LINE_MAX_LEN];

    total_length = 0;
    while ((cur_length = getline(cur_line, LINE_MAX_LEN)) != 0) {
        total_length = total_length + cur_length;
        if (total_length > LIMIT) {
            printf ("%s", cur_line);
        }
        if (cur_length < LINE_MAX_LEN) {
            printf ("\n");
            printf ("line length: %d\n", total_length);
            total_length = 0;
        }
    }

    return 0;
}

int getline(char cur_line[LINE_MAX_LEN], int max_len) {
    int index;
    int cur_char;
    int line_length;

    index = 0;
    line_length = 0;

    while (index < max_len - 1/* Don't forget to check index, and check first */
            && (cur_char = getchar()) != EOF 
            && cur_char != '\n' ) { 
        cur_line[index] = cur_char;
        index ++;
        line_length ++;
    }
    
    cur_line[line_length] = '\0'; /* Don't forget to set '\0' flag */

    return line_length;
}
