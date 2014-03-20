/*
 * Ex4.2
 * Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent
 */

#include <stdio.h>

#define LEN 200

int getline(char line[], int len);
double atof(char line[]);

int main(void) {
    char line[LEN];

    while(getline(line, LEN) != 0) {
        printf("%lf\n", atof(line));
    }
    return 0;
}

int getline(char line[], int len) {
    int c, i, cur_len;

    i = 0;
    while(i<len && (c=getchar()) != EOF) {
        line[i++] = c;
        if (c == '\n') {
            i--;
            break;
        }
    }
    line[i] = '\0';
    cur_len = i;

    return cur_len;
}

double atof(char line[]) {
    double val = 0.0;
    int i, sign, power, esign, epower, etimes;

    for (i=0; line[i]==' '; i++)
        ;
    if (line[i] == '-') {
        sign = -1;
        i++;
    } else {
        sign = 1;
    }

    while(line[i]!='.' && line[i]!='e' && line[i]!='E' && line[i]!='\0') {
        val = (10.0 * val + line[i] - '0');
        i++;
    }
    if (line[i] == '.') {
        i++;
    }

    power = 1.0;
    while(line[i]!= 'e' && line[i] != 'E' && line[i] != '\0') {
        val = (10.0 * val + line[i] - '0');
        power *= 10.0;
        i++;
    }

    epower = 0;
    if (line[i] == 'e' || line[i] == 'E') {
        i++;
        if (line[i] == '-') {
            i++;
            esign = -1;
        } else {
            esign = 1;
        }
        while (line[i] != '\0') {
            epower = epower * 10 + line[i] - '0';
            i++;
        }
    }
    etimes = 1;
    while (epower > 0) {
        etimes *= 10;
        epower --;
    }

    val = sign * val / power;
    if (esign < 0) {
        val /= etimes;
    } else {
        val *= etimes;
    }

    return val;


    return val;
}
