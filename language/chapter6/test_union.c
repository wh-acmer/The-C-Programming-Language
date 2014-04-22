/* test Unions */

#include <stdio.h>

union u_tag {
    short sval;
    int ival;
}ux, uy;

int main(void) {
    short x = 1;
    int y = 2;

    ux.sval = x;
    uy.ival = y;
    printf("%d %d\n", sizeof(ux), sizeof(uy));
    return 0;
}
