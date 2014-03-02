/*
 * Feature of The for statement and Symbolic Constant
 *
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
    int cur_fahr;

    for(cur_fahr = LOWER; cur_fahr <= UPPER; cur_fahr = cur_fahr + STEP) {
        printf("%3d %6.1f\n", cur_fahr, (5.0 / 9.0) * (cur_fahr - 32));
    }

    return 0;
}
