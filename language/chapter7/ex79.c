/*
 * exercise 7-9
 *
 * implement isupper, 
 * save time or save space
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARNUM 256

int isupper_save_time(int type_tables[], int c);
int isupper_save_space(int c);

int main(void) {
    int type_tables[CHARNUM];
    int c = 'A';
    int i;
    memset(type_tables, 0, sizeof(type_tables));
    for (i = 'A'; i <= 'Z'; i++) {
        type_tables[i] = 1;
    }


    printf ("%c is upper %d\n", c, isupper_save_space(c));
    printf ("%c is upper %d\n", c, isupper_save_time(type_tables, c));

    c = 'b';
    printf ("%c is upper %d\n", c, isupper_save_space(c));
    printf ("%c is upper %d\n", c, isupper_save_time(type_tables, c));

    c = '5';
    printf ("%c is upper %d\n", c, isupper_save_space(c));
    printf ("%c is upper %d\n", c, isupper_save_time(type_tables, c));

    return 0;
}

int isupper_save_time(int type_tables[], int c) {
    return type_tables[c];
}

int isupper_save_space(int c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}
