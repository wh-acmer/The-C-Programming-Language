/*
 * exercise 5-6
 * rewrite reverse(s), using pointers instead of index
 *
 */

#include <stdio.h>

void reverse(char *s);

int main(void) {
    char s[] = "abcd";

    printf ("%s\n", s);
    reverse(s);
    printf ("%s\n", s);
    reverse(s);
    printf ("%s\n", s);

    return 0;
}

void reverse(char *s) {
    char *t = s;
    char p;

    while (*s) {
        s++;
    }
    s--;

    while (t < s) {
        p = *t;
        *t = *s;
        *s = p;
        t++;
        s--;
    }
}
