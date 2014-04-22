/*
 * exercise 5-13
 *
 * tail -n
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TAIL_NUM 10
#define LINES_NUM 1000
#define LINE_LEN 100

int parse_cmd(int argc, char *argv[]);
int getlines(char *lines[], int maxlen);
int getline(char line[], int maxlen);
void output_tail_lines(char *lines[], int line_num, int tail_num);

int main(int argc, char *argv[]) {
    int tail_num, lines_num;
    char *lines[LINES_NUM];

    tail_num = parse_cmd(argc, argv);
    if (tail_num == -1) {
        tail_num = DEFAULT_TAIL_NUM;
    }
    lines_num = getlines(lines, LINES_NUM);
    output_tail_lines(lines, lines_num, tail_num);

    return 0;
}

int parse_cmd(int argc, char *argv[]) {
    int para_num;
    char *num;

    if (argc <= 1) {
        return -1;
    } else {
        num = argv[1] + 1;
        if (isdigit(num[0]) == 0) {
            return -1;
        }

        para_num = atoi(num);
        return para_num;
    }
}

int getlines(char *lines[], int maxlen) {
    char line[LINE_LEN];
    int lines_num = 0;
    int line_len;

    while ((line_len = getline(line, LINE_LEN)) > 0) {
        lines[lines_num] = (char *)malloc(sizeof(char) * line_len);
        strncpy(lines[lines_num], line, line_len);
        lines_num++;
    }

    return lines_num;
}

int getline(char line[], int maxlen) {
    int c, n;

    n = 0;
    while(n < maxlen && (c=getchar()) != EOF && c != '\n') {
        line[n++] = c;
    }
    if (n == 0) {
        return -1;
    }

    line[n++] = c;
    line[n] = '\0';

    return n;
}

void output_tail_lines(char *lines[], int lines_num, int tail_num) {
    int cur_i = lines_num - tail_num;

    if (cur_i < 0) {
        cur_i = 0;
    }

    while (cur_i < lines_num) {
        printf ("%s", lines[cur_i]);
        cur_i++;
    }
}
