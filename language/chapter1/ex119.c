/*
 * ex1-19:
 *  Write a function reverse(s) that reverses the character string s. 
 *  Use it to write a program that reverses its input a line at a time
 */

#include <stdio.h>

#define MAX_LINE_LEN 200

int getline(char cur_line[MAX_LINE_LEN], int max_len);

void reverse(char s[]);

int main(void) {
    char cur_line[MAX_LINE_LEN];

    while (getline(cur_line, MAX_LINE_LEN-1) != 0) {
        reverse(cur_line);
        printf ("%s\n", cur_line);
    }

    return 0;
}

void reverse(char s[]) {
    int begin, end;
    char tmp;

    begin = 0;
    end = 0;

    while (s[end] != '\0') {
        end ++;
    }
    end --; /* Don't forget it */

    while (begin < end) {
        tmp = s[begin];
        s[begin] = s[end];
        s[end] = tmp;

        begin ++;
        end --;
    }
}

int getline(char cur_line[MAX_LINE_LEN], int max_len) {
    int index;
    int cur_char;
    int line_length;

    index = 0;
    line_length = 0;

    while (index < max_len - 1  /* Don't forget to check index and check first */
           && (cur_char = getchar()) != EOF 
           && cur_char != '\n') { 
        cur_line[index] = cur_char;
        index ++;
        line_length ++;
    }
    
    cur_line[line_length] = '\0'; /* Don't forget to set '\0' flag */

    return line_length;
}
