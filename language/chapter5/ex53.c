/*
 * exercise 5-3
 * mstrcat(s, t) copy the string t to the end of s.
 */

#include <stdio.h>

void mstrcat(char *s, char *t);

int main(void) {
    char s[10] = "abc";
    char t[10] = "def";

    printf ("%s %s\n", s, t);
    mstrcat (s, t);
    printf ("%s %s\n", s, t);

    return 0;
}

void mstrcat(char *s, char *t) {
    while (*s++) {
        ;
    }
    s--;
    while ((*s++ = *t++)) {
        ;
    }
}
