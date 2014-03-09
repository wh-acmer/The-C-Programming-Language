/*
 * Ex 2.4
 * Write an alternative version of squeeze(s1,s2) that deletes each character 
 * in s1 that matches any character in the string s2
 */ 

#include <stdio.h>

void squeeze(char s[], char t[]);

int main(void) {
    char s[] = "abcdefh";
    char t[] = "cf";

    printf ("%s %s\n", s, t);
    squeeze (s, t);
    printf ("%s %s\n", s, t);
    return 0;
}

void squeeze(char s[], char t[]) {
    /* delete each character in s that matches any character in t */
    int i, j, k;

    i = j = k = 0;
    for (i=0; s[i]!='\0'; i++) {
        for (j=0; t[j]!='\0'; j++) {
            if (s[i] == t[j]) {
                break;
            }
        }

        /* s[i] doesn't match any character in t */
        if (t[j] == '\0') {
            s[k++] = s[i];
        } 
    }
    s[k] = '\0';
}
