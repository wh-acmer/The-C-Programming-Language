/* Ex2.3 convert a string of hex to integer */

#include <stdio.h>
#include <ctype.h>

char * to_lower_str(char s[]);
int htoi(char s[]);

int main(void) {
    char hex1[] = "0x09";
    char hex2[] = "0xaf";
    char hex3[] = "0xAF";

    printf ("tolower: %s %s %s\n", 
            to_lower_str(hex1), to_lower_str(hex2), to_lower_str(hex3));

    printf ("htoi: %d %d %d\n", 
            htoi(hex1), htoi(hex2), htoi(hex3));
    return 0;
}

int htoi(char s[]) {
    /*
     * Prefix of hex may be 0x or 0X
     *
     * The allowable digit is 0 - 9, a - f, A-F
     *
     */
    char *t = to_lower_str(s);
    int i, base, r;

    base = 16;
    r = 0;
    
    /* i = 2 to skip 0x or 0X */
    for (i=2; t[i]!='\0'; i++) {
        if (isdigit(t[i])) {
            r = r * base + t[i] - '0';
        } else if (islower(t[i]) && t[i]>='a' && t[i] <= 'f'){
            r = r * base + t[i] - 'a' + 10;
        } else if (isupper(t[i]) && t[i]>='A' && t[i] <= 'F'){
            r = r * base + t[i] - 'A' + 10;
        } else {
            /* impossible */
        }
    }

    return r;
}

char* to_lower_str(char s[]) {
    int i;
    for (i=0; s[i]!='\0'; i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
