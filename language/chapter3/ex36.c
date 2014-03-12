/*
 * Ex36
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enoug
 *  
 */

#include <stdio.h>
#include <limits.h>

#define LEN 200

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
    int min_int = INT_MIN;
    int width = 10;
    char s[LEN];

    itoa(min_int, s, width);
    printf ("%s\n", s);

    width = 12;
    itoa(min_int, s, width);
    printf ("%s\n", s);
    

    return 0;
}

void itoa(int n, char s[], int w) {
    int sign, i, c;

    c = 0;
    if (n < 0) {
        sign = -1;
        n =  n + 1;
        n =  0 - n;
        c = 1;
    } else {
        sign = 1;
    }

    i = 0;
    do {
        s[i++] = (n % 10 + c) % 10 + '0';
        c = (n % 10 + c) / 10;
    }while (n /= 10);

    if (sign < 0) {
        s[i++] = '-';
    }

    while (w - i > 0) {
        s[i++] = ' ';
    }
    s[i] = '\0';

    reverse(s); 
}

void reverse(char s[]) {
    int i, j, t;

    i = j = 0;
    while (s[j] != '\0') {
        j++;
    }
    j--;

    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}
