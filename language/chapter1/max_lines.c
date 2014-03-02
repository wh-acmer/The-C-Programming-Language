/*
 * Output lines which has maximum length
 *
 */


#include <stdio.h>

#define LINE_MAX_LEN 200

int getline(char cur_line[LINE_MAX_LEN], int max_len);

void copy_line(char src_line[LINE_MAX_LEN], char des_line[LINE_MAX_LEN]);

int main(void) {
    int cur_length;
    int max_length;
    char cur_line[LINE_MAX_LEN];
    char max_line[LINE_MAX_LEN];

    max_length = 0;

    while ((cur_length = getline(cur_line, LINE_MAX_LEN)) != 0) {
        if (cur_length > max_length) {
            copy_line (cur_line, max_line);
            max_length = cur_length;
        }
    }

    printf ("Max line is:\n");
    printf ("%s\n", max_line);


    return 0;
}


int getline(char cur_line[LINE_MAX_LEN], int max_len) {
    int index;
    int cur_char;
    int line_length;

    index = 0;
    line_length = 0;

    while (index < maxlen - 1 /* Don't forget to check index and check first */
           && (cur_char = getchar()) != EOF 
           && cur_char != '\n') { 
        cur_line[index] = cur_char;
        index ++;
        line_length ++;
    }
    
    cur_line[line_length] = '\0'; /* Don't forget to set '\0' flag */

    return line_length;
}

void copy_line(char src_line[LINE_MAX_LEN], char des_line[LINE_MAX_LEN]) {
    int index;

    index = 0;
    while (index < LINE_MAX_LEN - 1 && src_line[index] != '\0') {
        des_line[index] = src_line[index];
        index ++;
    }
    des_line[index] = '\0'; /* Don't forget to set '\0' */
}
