/*
 * Ex1-24
 *
 *  Write a program to check a C program for rudimentary syntax errors like
 *  unmatched parentheses, brackets and braces. Don’t forget about quotes, 
 *  both single and double, escape sequences, and comments. 
 *  (This program is hard if you do it in full generality.)
 *
 */

#include <stdio.h>

#define ERROR 0
#define SUCCESS 1

#define NORMAL 0
#define S_QUOTE 1
#define D_QUOTE 2
#define DEFINE 3
#define COMMENT 4

#define STACK_DEPTH 200
#define MSG_LEN 200

#define NULL_CHAR ' '

#define TRUE 1
#define FALSE 0


int state;
int change_state(int cur_char, int last_char);

char paren_stack[STACK_DEPTH];
int paren_stack_top;
int push_paren(char cur_char);
char pop_paren();
char get_top_paren();
int is_empty_paren();

int check_paren_match(int cur_char);
int is_match(char pre_paren, char back_paren);


char pre_paren_set[] = {'(', '{', '['};
char back_paren_set[] = {')', '}', ']'};

int main(void) {
    extern int state;
    extern int paren_stack_top;

    int last_char, cur_char;
    int line_num;
    int check_state;

    last_char = ' ';
    state = NORMAL;
    paren_stack_top = 0;
    line_num = 1;

    while ((cur_char = getchar()) != EOF) {
        if (cur_char == '\n') {
            line_num ++;
        }

        check_state = check_paren_match(cur_char);
        if (ERROR == check_state) {
            break;
        }

        change_state(cur_char, last_char);
        last_char = cur_char;
    }

    if (is_empty_paren() == FALSE || check_state == ERROR) {
        printf ("line %d: parentheses does not match.\n", line_num);
    }

    return 0;
}

int check_paren_match(int cur_char)
{
    extern int state;
    char pre_paren;

    if (state == NORMAL) {
        if (cur_char == '('
            || cur_char == '['
            || cur_char == '{') {
            push_paren(cur_char);
        } else {
            if (cur_char == ')' 
                || cur_char == ']' 
                || cur_char == '}') {
                pre_paren = get_top_paren();
                if (pre_paren != NULL_CHAR && is_match(pre_paren, cur_char)) {
                    pop_paren();
                } else {
                    return ERROR;
                }
            }
        }
    }

    return SUCCESS;
}


int change_state(int cur_char, int last_char) {
    extern int state;

    if (state == NORMAL) {
        if (cur_char == '"') {
            state = D_QUOTE;
        } else if (cur_char == '\'') {
            state = S_QUOTE;
        } else if (last_char == '#' && cur_char == 'd') {
            state = DEFINE;
        } else if (last_char == '/' && cur_char == '*') {
            state = COMMENT;
        } else {
            state = NORMAL;
        }
    } else if (state == S_QUOTE) {
        if (cur_char == '\'') {
            state = NORMAL;
        } else {
            state = S_QUOTE;
        }
    } else if (state == D_QUOTE) {
        if (cur_char == '"') {
            state = NORMAL;
        } else {
            state = D_QUOTE;
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


int push_paren(char cur_char) {
    extern int paren_stack_top;
    extern char paren_stack[];

    if (paren_stack_top >= STACK_DEPTH) {
        return ERROR;
    } else {
        paren_stack[paren_stack_top++] = cur_char;
        return SUCCESS;
    }
}

char pop_paren() {
    extern int paren_stack_top;
    extern char paren_stack[];

    if (paren_stack_top == 0) {
        return NULL_CHAR;
    } else {
        return paren_stack[--paren_stack_top];
    }
}

char get_top_paren() {
    extern int paren_stack_top;
    extern char paren_stack[];

    if (paren_stack_top == 0) {
        return NULL_CHAR;
    } else {
        return paren_stack[paren_stack_top - 1];
    }
}

int is_empty_paren() {
    if (paren_stack_top == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int is_match(char pre_paren, char back_paren) {
    int paren_index;
    int paren_len;

    paren_index = 0;
    paren_len = sizeof(pre_paren_set) / sizeof(char);

    for (paren_index = 0; paren_index < paren_len; paren_index ++) {
        if ((pre_paren == pre_paren_set[paren_index])
            && (back_paren == back_paren_set[paren_index])) {
            return TRUE;
        }
    }

    return FALSE;
}
