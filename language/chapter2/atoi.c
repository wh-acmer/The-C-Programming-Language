/* convert string to integer */

#include <stdio.h>

int atoi(char str[]);

int main(void) {
    char *str = "123";
    int str_int = atoi(str);

    printf ("string %s is integer %d\n", str, str_int);

    return 0;
}

int atoi(char str[]) {
    int i, str_int, base;

    str_int = 0;
    base = 10;

    for (i=0; str[i]!='\0'; i++) {
        str_int = base * str_int + (str[i] - '0');
    }

    return str_int;
}
