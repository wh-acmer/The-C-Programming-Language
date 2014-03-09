/*
 * Ex 2.5
 * Write the function any(s1,s2), which returns the first location 
 * in a string s1 where any character from the string s2 occurs, 
 * or -1 if s1 contains no characters from s2. (The standard library
 * function strpbrk does the same job but returns a pointer to the location.)
 * 
 */

#include <stdio.h>

int any(char s[], char t[]);

int main(void) {
    char s1[] = "abcde";
    char t1[] = "d";
    char t2[] = "fg";

    printf ("%s %s %d\n", s1, t1, any(s1, t1));
    printf ("%s %s %d\n", s1, t2, any(s1, t2));
    return 0;
}

int any(char s[], char t[]) {
    int i, j;

    for (i=0; s[i]!='\0'; i++) {
        for (j=0; t[j]!='\0'; j++) {
            if (s[i] == t[j]) {
                return i;
            }
        }
    }

    return -1;
}
