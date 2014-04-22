/*
 * exercise 5-14
 *
 * add option -r to sort,
 * make sure it works well with -n
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int numeric, reverse, c;

    numeric = 0;
    reverse = 0;

    while (--argc && (*++argv)[0] == '-') {
        while((c=*++argv[0])) {
            switch(c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf ("bad optioin.\n");
                    break;
            }
        }
    }

    printf("%d\n", numeric);
    printf("%d\n", reverse);

    return 0;
}
