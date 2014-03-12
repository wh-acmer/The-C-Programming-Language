/*
 * Ex3.5
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s.  In particular, itob(n,s,16)
 * formats s as a hexadecimal integer in s
 */

#include <stdio.h>

#define LEN 200

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    int n, b;
    char s[LEN];

    n = 15;
    b = 16;
    itob(n, s, b);

    printf ("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b) {
    int sign, i, c;
    int base = b;

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
        s[i] = (n % base + c) % base;
        s[i] = (s[i] >= 10) ? (s[i]-10+'a') : (s[i]+'0');
        c = (n % base + c) / base;
        i++;
    }while (n /= base);

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
