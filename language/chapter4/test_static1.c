#include <stdio.h>

void foo() {
}

static void bar() {
}

int i = 3;
static int j = 4;

int main(void){
    printf ("%d \n", i);
    printf ("%d \n", j);
    return 0;
}
