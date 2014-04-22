/*
 * exercise 6-1
 *
 * improve getword to process
 *
 * underscore, comments, preprocessor control lines
 */

#include <stdio.h>
#include <ctype.h>

#define WORDLEN 100
#define BUFSIZE 100

#define NORMAL 0
#define COMMENT 1
#define MACRO 2

int getword(char *word, int wordlen);
int isvalid_varchar(int c);
int is_useless_input(int c);
int state = NORMAL;

char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int c);

int main(void) {
    char word[WORDLEN];

    while (getword(word, WORDLEN) != EOF) {
        printf ("%s\n", word);
    }

    return 0;
}

int getword(char *word, int wordlen) {
    int c;
    char *w = word;

    while (is_useless_input(c = getch())) {
        ;
    }

    if (c != EOF) {
        *w++ = c;
    }

    if (!isvalid_varchar(c)) {
        *w = '\0';
        return c;
    }

    for (; --wordlen > 0; w++) {
        if (!isvalid_varchar(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int isvalid_varchar(int c) {
    if (isalnum(c) || c == '_') {
        return 1;
    } else {
        return 0;
    }
}

int is_useless_input(int c) {
    char c1;

    if (state == NORMAL) {
        if (isspace(c)) {
            return 1;
        } else if (c == '#') {
            state = MACRO;
            return 1;
        } else if (c == '/') {
            c1 = getch();
            if (c1 == '*') {
                state = COMMENT;
                return 1;
            } else {
                ungetch(c1);
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        if (state == MACRO && c == '\n') {
            state = NORMAL;
        } else if (state == COMMENT && c == '*') {
            c1 = getch();
            if (c1 == '/') {
                state = NORMAL;
            } else {
                ungetch(c1);
            }
        }
        return 1;
    }
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf ("ungetch: too many characters.\n");
    } else {
        buf[bufp++] = c;
    }
}
