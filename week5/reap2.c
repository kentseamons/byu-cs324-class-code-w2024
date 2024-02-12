#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/* # Install signal handler b - loop to reap children
 * # This is an attempt to fix the problem in reap1.c
 *
 * $ gcc -o reap2 reap2.c
 * $ ./reap2
 * # The signal handler is called once.
 * # Handler pauses. All the children are reaped.
 * # Why? Because wait is a blocking call and will pause
 * # as long as there are children processes running.
 *
 * # The signal handler is called a second time with 
 * # no children to reap. Why? 
 * # Because the pending but was set during the earlier call
 * # to the signal handler that actually reaped the child 
 * # that generated the signal while the handler was being run.
 */

void sig_handler_a(int signo)
{
    int status;
    printf("Entering sig handler a\n");
    fflush(stdout);
    pid_t pid=wait(&status);    
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

    if (signal(SIGCHLD, sig_handler_b) == SIG_ERR)
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
        sleep(15);
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
    sleep(2);
    sleep(2);
    printf("Exiting parent\n");
    
}
