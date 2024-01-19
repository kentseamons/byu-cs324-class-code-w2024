#include <unistd.h>
#include <stdio.h>

/*
 * $ gcc -o fork fork.c
 * $ ./fork
 */
int main() {
	int ret;
	printf("before fork\n");
	ret = fork();
	printf("ret = %d\n", ret);
}
