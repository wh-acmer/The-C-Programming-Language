/* get operation from input */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char str[]) {
    int c, i, cmd;

    /* skip ' ' and '\t' */
    while((c=getch()) != EOF) {
        if (c != ' ' && c != '\t') {
            break;
        }
    }

    /* not a number */
    if(isdigit(c) == 0 && c != '.') {
        if (c == '-') {
            c = getch();
            ungetch(c);
            if (isdigit(c) == 0) {
                return '-';
            } else {
                c = '-';
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
                return c;
            }
        }
    }

    /* put number into str */
    ungetch(c);
    i = 0;
    while((c=getch()) != EOF) {
        if (isdigit(c) || c == '.' || c == '-') {
            str[i++] = c;
        } else {
            break;
        }
    }
    str[i] = '\0';
    ungetch(c);

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
            cstart = getch();
            stack[top++] = cstart;
            j++;
        }
        if (cmds[i][j] == '\0') {
            ungetch(stack[--top]);
            return cmd_flag[i];
        } else {
            while(j--) {
                ungetch(stack[--top]);
            }
        }
    }
    return NONECMD;
}

int parse_var(int cstart) {
    int c;
    if (islower(cstart)) {
        c = getch();
        ungetch(c);
        if (isalpha(c) == 0) {
            return VAR;
        } 
    } 
    return NONECMD;
}
