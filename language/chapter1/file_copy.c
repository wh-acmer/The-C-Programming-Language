/*
 * Copy input to Output
 * Using getchar and putchar
 *
 */

#include <stdio.h>

int main(void) {
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}
