#include<stdio.h>

/*
 * concatenate files to stdout
 * $ cat test.txt
 * $ cat
 * $ cat < test.txt
 *
 * $ gcc -o pipe-hello pipe-hello.c
 * $ ./pipe-hello | grep OUT
 * $ ./pipe-hello | grep FOO
 */
int main(int argc, char *argv[]) {
	fprintf(stdout, "hello STDOUT\n");
}
