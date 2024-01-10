#include<stdio.h>

/*
 * $ gcc -o stdin stdin.c
 * $ .stdin
 */
int main(int argc, char *argv[]) {
	char buf[1024];
    printf("Enter your input:");
	fgets(buf, 512, stdin);
	printf("%s\n", buf);
}
