/*
 * Ex4.13
 * Write a recursive version of function reverse(s)
 */

#include <stdio.h>

void reverse(char s[]);
void reverse_recur(char s[], int start, int end);
void swap(char s[], int i, int j);

int main(void) {
    /* char s[] = "asdf"; */
    char s[] = "asedf";

    reverse(s);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[]) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    reverse_recur(s, 0, i-1);
}

void reverse_recur(char s[], int start, int end) {
    if (start >= end) {
        return;
    }
    swap(s, start, end);
    reverse_recur(s, start+1, end-1);
}


void swap(char s[], int i, int j) {
    int t = s[i];
    s[i] = s[j];
    s[j] = t;
}
