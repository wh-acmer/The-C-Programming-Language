/*
 * Ex3.2
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like
 * \n and \t as it copies the string t to s. Use a switch. Write a function for
 * the other direction as well, converting escape sequences into the real
 * characters.
 */

#include <stdio.h>

#define LEN 200
#define BEGIN 1
#define END 0

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
    char s[LEN];
    char p[LEN];
    char t[LEN] = "ab\tc\nd";

    escape(s, t);
    printf ("%s\n--\n", t);
    printf ("%s\n--\n", s);

    unescape(p, s);
    printf ("%s\n--\n", s);
    printf ("%s\n--\n", p);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[j] != '\0') {
        switch(t[j]) {
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            default:
                s[i++] = t[j];
                break;
        }
        j++;
    }
    s[i] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    int slash;

    i = j = 0;
    slash = END;
    while (t[j] != '\0') {
        switch(t[j]) {
            case '\\':
                slash = BEGIN;
                break;
            case 't':
                if (slash == BEGIN) {
                    s[i++] = '\t';
                    break;
                }
                /* go through to default */
            case 'n':
                if (slash == BEGIN) {
                    s[i++] = '\n';
                    break;
                }
                /* go through to default */
            default:
                slash = END;
                s[i++] = t[j];
        }
        j++;
    }
    s[i] = '\0';
}
