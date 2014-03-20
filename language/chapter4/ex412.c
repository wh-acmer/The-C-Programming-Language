/* 
 * Ex4.12
 * Use recursive to write itoa
 */

#include <stdio.h>

#define NUMLEN 200

void itoa(int num, char num_str[]);

int main(void) {
    int num;
    char num_str[NUMLEN];

    num = 1023;
    itoa(num, num_str);
    printf("%s\n", num_str);

    return 0;
}


void itoa(int num, char num_str[]) {
    int i;
    if (num / 10 == 0) {
        num_str[0] = num % 10 + '0';
        num_str[1] = '\0';
    } else {
        itoa(num / 10, num_str);
        i = 0;
        while (num_str[i] != '\0') {
            i++;
        }
        num_str[i] = num % 10 + '0';
        num_str[i+1] = '\0';
    }
}
