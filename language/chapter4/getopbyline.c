/* get operation from mgetline */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define LINE_LEN 1000

char line[LINE_LEN];
int line_i = 0;

void mgetline(char line[]) {
    int i = 0;
    int c;

    while ((c=getchar()) && c != '\n' && c != EOF) {
        line[i++] = c;
    }
    line[i] = '\n';
}

int getop(char str[]) {
    int i, c, cmd;
    if (line_i == 0) {
        mgetline(line);
    }

    /* skip ' ' and '\t' */
    while((c=line[line_i++]) != '\0') {
        if (c != ' ' && c != '\t') {
            break;
        }
    }

    /* not a number */
    if(isdigit(c) == 0 && c != '.') {
        if (c == '-') {
            if (isdigit(line[line_i]) == 0) {
                return '-';
            } 
        } else {
            if (parse_var(c) == VAR) {
                str[0] = c;
                str[1] = '\0';
                return VAR;
            }

            if ((cmd = parse_cmd(c)) != NONECMD) {
                return cmd;
            } else {
                if (c == '\n') {
                    line_i = 0;
                }
                return c;
            }
        }
    }

    /* put number into str */
    line[--line_i] = c;
    i = 0;
    while((c=line[line_i++]) != EOF) {
        if (isdigit(c) || c == '.' || c == '-') {
            str[i++] = c;
        } else {
            break;
        }
    }
    str[i] = '\0';
    line[--line_i] = c;

    return NUMBER;
}

int parse_cmd(int cstart) {
    /* each item of cmds matches a item in cmd_flag */
    char cmds[][CMD_LEN] = { "sin", "cos", "pow", "x" };
    int cmd_flag[] = { SIN, COS, POW, VAR };
    int len = sizeof(cmds) / (sizeof(char) * CMD_LEN);
    int i, j, top;
    char stack[200];

    top = 0;
    for (i=0; i<len; i++) {
        j = 0;
        while (cmds[i][j] != '\0' && cstart == cmds[i][j]) {
            cstart = line[line_i++];
            stack[top++] = cstart;
            j++;
        }
        if (cmds[i][j] == '\0') {
            line[--line_i] = stack[--top];
            return cmd_flag[i];
        } else {
            while(j--) {
                line[--line_i] = stack[--top];
            }
        }
    }
    return NONECMD;
}

int parse_var(int cstart) {
    int c;
    if (islower(cstart)) {
        c = line[line_i];
        if (isalpha(c) == 0) {
            return VAR;
        } 
    } 
    return NONECMD;
}
