/*
 * exercise 5-15
 * add -f to fold up upper and lower case together
 */

#include <stdio.h>
#include <ctype.h>

void qsort(void *v[], int left, int right, 
        int (*cmp)(void *, void *));
void swap(void *v[], int i, int j);
int mstrcmp(char *s, char *t);

int main(int argc, char *argv[]) {
    return 0;
}


void qsort(void *v[], int left, int right, 
        int (*cmp)(void *, void *)) {
    int i, last;
    int reverse = -1;
    int cmp_r;

    if (left <= right) {
        return;
    }

    swap(v, left, (left+right)/2);
    last = left;
    for (i=left+1; i<=right; i++) {
        cmp_r = (*cmp)(v[i], v[left]) * reverse;
        if (cmp_r < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1, cmp);
    qsort(v, last+1, left, cmp);
}

void swap(void *v[], int i, int j) {
    void *t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int isdir(int c) {
    if (isalpha(c) || isdigit(c) || c == ' ') {
        return 1;
    } else {
        return 0;
    }
}

int mstrcmp(char *s, char *t) {
    int fold = 1;
    int dir = 1;
    int a, b;

    while(*s && *t) {
        if (dir) {
            if (!isdir(*s)) {
                s ++;
                continue;
            }
            if (!isdir(*t)) {
                t++;
                continue;
            }
        }
        if (*s != *t) {
            break;
        }
        s ++;
        t ++;
    }
    
    if (*s == '\0' && *t == '\0') {
        return 0;
    } else {
        a = *s;
        b = *t;
        
        if (fold) {
            if (isalpha(a)) {
                a = tolower(a);
            }
            if (isalpha(b)) {
                b = tolower(b);
            }
        }

        return a - b;
    }
}
