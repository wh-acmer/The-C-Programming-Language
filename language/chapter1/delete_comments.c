/*
 * Ex1-23
 *
 * Write a program to remove all comments from a C program. Don’t forget 
 * to handle quoted strings and character constants properly. C comments 
 * don’t nest.
 *
 */

/* Using Finit-State Machine to solve this problem */


#include <stdio.h>

#define NORMAL 0
#define QUOTE 1
#define DEFINE 2
#define COMMENT 3

int change_state(int cur_char, int last_char);
void output_char(int cur_char);

int state;

int main(){
    int last_char, cur_char;

    /* 
     * In fact, this declaration can be neglect when it's define 
     * is before it in  the same file 
     */
    extern int state; 

    state = NORMAL;
    last_char = ' ';

    while ((cur_char = getchar()) != EOF) {
        output_char(cur_char);
        change_state(cur_char, last_char);
        last_char = cur_char;
    }

    return 0;
}

void output_char(int cur_char) {
    extern int state;
    int next_char;
    int cur_state;

    if (state == NORMAL && cur_char == '/') {
        next_char = getchar();
        cur_state = change_state(next_char, cur_char);
        if (cur_state != COMMENT) {
            putchar (cur_char);
            putchar (next_char);
        }
    } else {
        if (state != COMMENT) {
            putchar (cur_char);
        }
    }
}


int change_state(int cur_char, int last_char) {
    extern int state;

    if (state == NORMAL) {
        if (cur_char == '"') {
            state = QUOTE;
        } else if (last_char == '#' && cur_char == 'd') {
            state = DEFINE;
        } else if (last_char == '/' && cur_char == '*') {
            state = COMMENT;
        } else {
            state = NORMAL;
        }
    } else if (state == QUOTE) {
        if (cur_char == '"') {
            state = NORMAL;
        } else {
            state = QUOTE;
        }
    } else if (state == DEFINE) {
        if (cur_char == '\n') {
            state = NORMAL;
        } else {
            state = DEFINE;
        }
    } else if (state == COMMENT) {
        if (last_char == '*' && cur_char == '/') {
            state = NORMAL;
        } else {
            state = COMMENT;
        }
    } else {
        /* Can not happen */
    }

    return state;
}
