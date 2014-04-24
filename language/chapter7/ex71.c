/*
 * exercise 7-1
 * convert upper case to  lower
 * or lower case to upper, depend
 * on the name it is invoked with, 
 * as found in argv[0]
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    int upper = 1;
    int c;

    if (argc > 1 && strncmp(argv[1], "lower", 6) == 0) {
        upper = 0;
    }

    if (upper == 1) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    } else {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    }
    return 0;
}
