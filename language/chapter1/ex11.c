/*
 * Excercise 1-1
 *
 */

int main() {
    printf("hello, world.\n");
}

/*
 * Result after compile:
 *
 * ex11.c: In function ‘main’:
 * ex11.c:7:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 * ex11.c:7:5: warning: incompatible implicit declaration of built-in function ‘printf’ [enabled by default]
 * ex11.c:8:1: warning: control reaches end of non-void function [-Wreturn-type]
 *
 */
