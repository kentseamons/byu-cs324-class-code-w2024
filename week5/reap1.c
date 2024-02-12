#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
 * # Signal handler a - catch SIGCHLD signals and reap the child using wait
 * $ gcc -o reap1 reap1.c
 * $ ./reap1
 * # parent forks 3 children
 * # observe that only two children are reaped. Why?
 * # Two SIGCHLD signals are received at about the same time
 * # and only one pending bit is set. We can't count the number 
 * # of signals sent in a signal handler
 * # This strategy for wait does not work
 */

void sig_handler_a(int signo)
{
    int status;
    printf("Entering sig handler a\n");
    fflush(stdout);
    pid_t pid = wait(&status);    
    printf("Reaped a child %d\n",pid);
    fflush(stdout);
    printf("Exiting sig handler a\n");
    fflush(stdout);
}

void sig_handler_b(int signo)
{
    int status;
    printf("Entering sig handler b\n");
    fflush(stdout);
    pid_t pid;
    while ((pid=wait(&status))>0) {
        printf("Reaped a child %d\n",pid);
        fflush(stdout);
    }
    printf("Exiting sig handler b\n");
    fflush(stdout);
}


int main() {
	int ret;
	int status;

    sigset_t mask, prev_mask;

    if (signal(SIGCHLD, sig_handler_a) == SIG_ERR)
        printf("signal handler setup failed\n");

    ret = fork();
	if (ret == 0) {
		printf("I am child 1!! ret=%d pid=%d ppid=%d\n",
               ret, getpid(), getppid());
		sleep(2);
        printf("Client 1 exiting\n");
        fflush(stdout);
        exit(1);
	}
    ret = fork();
    if (ret == 0) {
        printf("I am child 2!! ret=%d pid=%d ppid=%d\n",
               ret, getpid(), getppid());
        sleep(2);
        printf("Client 2 exiting\n");
        fflush(stdout);
        exit(2);
    }
    ret = fork();
    if (ret == 0) {
        printf("I am child 3!! ret=%d pid=%d ppid=%d\n",
               ret, getpid(), getppid());
        sleep(1);
        printf("Client 3 exiting\n");
        fflush(stdout);
        exit(8);
    }

    
    sleep(10);

    //    if (signal(SIGCHLD, sig_handler_b) == SIG_ERR)
    //        printf("signal handler setup failed\n");
    //    printf("Installed handler\n");


    sleep(12);
    sleep(2);
    sleep(2);
    printf("Exiting parent\n");
    
}
