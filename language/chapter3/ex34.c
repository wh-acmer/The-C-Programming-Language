/*
 * Ex34
 * In a two’s complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2wordsize-1). Explain why not. Modify it to print that value correctly,
 *  regardless of the machine on which it runs
 * 
 */

#include <stdio.h>
#include <limits.h>

#define LEN 200

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
    int min_int = INT_MIN;
    char s[LEN];

    itoa(min_int, s);

    printf ("%d\n", min_int);
    printf ("%s\n", s);

    return 0;
}

void itoa(int n, char s[]) {
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
