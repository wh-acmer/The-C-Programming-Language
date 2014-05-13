/*
 * exercise 8-1
 * use unix API read, write, open, close
 * instead of standard library to implement
 * cat
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 100

int main(int argc, char **argv) {
    int n, f1;

    char arg_error_msg[] = "cat: arg error\n";
    char file_open_error_msg[] = "cat: can not open file\n";
    char file_read_error_msg[] = "cat: read file error\n";
    char buf[BUFSIZE];

    if (argc < 1) {
        write(2, arg_error_msg, sizeof(arg_error_msg));
        exit(1);
    }

    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        write(2, file_open_error_msg, sizeof(file_open_error_msg));
        exit(2);
    }

    while ((n = read(f1, buf, BUFSIZE)) > 0) {
        if (write(1, buf, n) != n) {
            write(2, file_read_error_msg, sizeof(file_read_error_msg));
            exit(3);
        }
    }

    exit(0);
}
