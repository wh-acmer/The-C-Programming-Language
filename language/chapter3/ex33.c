/*
 * Ex 3.3
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent
 * complete list abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that
 * a leading or trailing - is taken literally.
 * 
 */
#include<stdio.h>

#define LEN 200

void expand(char s1[], char s2[]);

int main(void) {
    char s1[LEN] = "this is a a-e to 0-9 to a-c0-4";
    char s3[LEN] = "--";
    char s2[LEN];

    printf ("s1:%s\n", s1);
    expand(s1, s2);
    printf ("s2:%s\n", s2);

    printf ("s3:%s\n", s3);
    expand(s3, s2);
    printf ("s2:%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j, k;

    j = 0;
    for (i=0; s1[i]!='\0'; i++) {
        if (s1[i] != '-' || i == 0 || s1[i+1] == '\0') {
            s2[j++] = s1[i];
        } else {
            for (k=s1[i-1]+1; k<s1[i+1]; k++) {
                s2[j++] = k;
            }
        }
    }
    s2[j] = '\0';
}
