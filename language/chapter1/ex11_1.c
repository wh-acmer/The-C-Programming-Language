/*
 * Excercise 1-1
 *
 */

main() {
    printf("hello, world.\n");
}

/*
 * Result after compile:
 *
 * ex11_1.c:6:1: warning: return type defaults to ‘int’ [-Wreturn-type]
 * ex11_1.c: In function ‘main’:
 * ex11_1.c:7:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 * ex11_1.c:7:5: warning: incompatible implicit declaration of built-in function ‘printf’ [enabled by default]
 * ex11_1.c:8:1: warning: control reaches end of non-void function [-Wreturn-type]
 *
 */
