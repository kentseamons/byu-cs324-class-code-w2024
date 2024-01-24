#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

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
	int status;
	ret = fork();
	if (ret == 0) {
		printf("I am the child!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
		sleep(5);
        printf("Client exiting\n");
	} else {
		printf("I am the parent!! ret=%d pid=%d ppid=%d\n",
				ret, getpid(), getppid());
		printf("before wait\n");
        sleep(10);
		wait(&status);
		printf("after wait\n");
		sleep(5);
	}
}
