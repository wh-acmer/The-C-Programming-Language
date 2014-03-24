/*
 * exercise 5-5
 * mstrncpy(s, t, n) copy at most n characters of t to s
 */

#include <stdio.h>
#include <string.h>

void mstrncpy(char *s, char *t, int n);

int main(void) {
    char s[10];
    char t[10] = "abc";
    int lt = strlen(t);

    mstrncpy(s, t, lt-1);
    printf ("%s\n", s);

    mstrncpy(s, t, lt);
    printf ("%s\n", s);

    mstrncpy(s, t, lt+1);
    printf ("%s\n", s);

    return 0;
}

void mstrncpy(char *s, char *t, int n) {
    int i = 0;
    while ((*s++ = *t++) && ++i < n) {
        ;
    }
    *s = '\0';

}
