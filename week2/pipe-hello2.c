#include<stdio.h>

/*
 * concatenate files to stdout
 * $ cat test.txt
 * $ cat
 * $ cat < test.txt
 *
 * $ gcc -o pipe-hello2 pipe-hello2.c
 * $ ./pipe-hello2 | grep OUT
 * $ ./pipe-hello2 | grep FOO
 *
 * How is standard error handled using pipes?
 *
 */
int main(int argc, char *argv[]) {
    fprintf(stdout, "hello STDOUT\n");
    fprintf(stderr, "hello STDERR\n");
}
