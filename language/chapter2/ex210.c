/*
 * Ex210
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else
 */

#include <stdio.h>

char * lower(char s[]);

int main(void) {
    char s[] = "Harry Potter";
    printf ("%s\n", s);
    printf ("%s\n", lower(s));
    return 0;
}

char * lower(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = (s[i]>='A' && s[i]<='Z') ? (s[i] - 'A' + 'a') : s[i];
        i++;
    }
    return s;
}
