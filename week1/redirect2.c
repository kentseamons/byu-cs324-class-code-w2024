#include <stdio.h>

// ./redirect2 2>&1  | cat | grep 2
// ./redirect2 1>&2  | cat | grep 2

int main() {
	fprintf(stderr, "abc\n");
	fprintf(stdout, "234\n");
}
