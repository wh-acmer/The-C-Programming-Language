/* Manage variables */

#include <stdio.h>
#include "calc.h"

#define VARLEN 26

static int varp = 0;

static double vars[VARLEN];

void setvar(double dval) {
    varp = (varp + 1) % VARLEN;
    vars[varp % VARLEN] = dval;
}

double getvar(int last) {
    if (last >= 0 && last <= (VARLEN-1)) {
        return vars[(varp + VARLEN - last) % VARLEN];
    } else {
        printf ("getvar: var name error\n");
        return 0.0;
    }
}
