/* Ex 2.2 */

#include <stdio.h>

#define LIM 10

int main(void) {
    int i, c, lim;
    char s[LIM + 1];

    lim = LIM;
    /* Original Version of for loop */
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; i++)
        s[i] = c;

    /* New Version of for loop without && or || */
    for (i=0; i<lim-1; i++) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
    }


    return 0;
}
