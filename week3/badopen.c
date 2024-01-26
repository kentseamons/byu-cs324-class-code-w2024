#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

/*
 * $ gcc -o badopen badopen.c
 * $ ./badopen does-not-exist.txt
 * $ ./badopen /etc/shadow
 */
int main(int argc, char *argv[]) {
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		// note that the string passed to perror() is
		// arbitrary, and is only intended to provide
		// some context for the error.
		perror("open failed");
        printf("errno: %d\n",errno);
		exit(1);
	}
}
