/*
 * exercise 5-4
 * strend(s, t) whether t is in the end of s
 */

#include <stdio.h>

int strend(char *s, char *t);

int main(void) {
    char *s0 = "abcdef";
    char *t0 = "def";

    char *s1 = "abcdef";
    char *t1 = "kef";

    printf ("strend(%s, %s) = %d\n", s0, t0, strend(s0, t0));
    printf ("strend(%s, %s) = %d\n", s1, t1, strend(s1, t1));
    printf ("strend(%s, %s) = %d\n", t0, s0, strend(t0, s0));
    printf ("strend(%s, %s) = %d\n", t1, s1, strend(t1, s1));

    return 0;
}

int strend(char *s, char *t) {
    char *ot = t;
    char *os = s;

    while (*s) {
        s++;
    }

    while (*t) {
        t++;
    }

    while (s != os && t != ot && *s == *t) {
        s--;
        t--;
    }

    return t == ot && *s == *t;
}
