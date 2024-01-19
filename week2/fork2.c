#include <unistd.h>
#include <stdio.h>

/*
 * $ gcc -o fork fork.c
 * $ ./fork
 * # in another terminal, within 10 seconds:
 * $ ps -ef | grep fork
 * # in another terminal, between 10 and 60 seconds:
 * $ ps -ef | grep fork
 */
int main() {
	int ret;
	ret = fork();
	if (ret == 0) {
		printf("I am the child!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
		sleep(60);
	} else {
		printf("I am the parent!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
		sleep(10);
	}
	sleep(1);
}
