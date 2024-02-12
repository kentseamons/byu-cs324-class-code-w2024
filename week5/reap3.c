#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/* # Install signal handler b - loop to reap children
 * # Use WNOHANG to avoid blocking when no child ready to be reaped.
 * # The signal handler exits when no more children ready to be reaped.
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
    int wstatus;
    printf("Entering sig handler b\n");
    fflush(stdout);
    pid_t pid;
    //    while ((pid=waitpid(-1,&status,WNOHANG))>0) {
    //    printf("Reaped a child %d\n",pid);
    //    fflush(stdout);
    //}

    do {
        printf("Calling waitpid\n");
        pid = waitpid(-1, &wstatus, WNOHANG | WUNTRACED | WCONTINUED);        
        if (pid == -1) {
            perror("waitpid");
            // exits when no more children. Your shell should continue.
            exit(EXIT_FAILURE);
        }
        if (pid==0) {
            printf("Children exist. No child ready to be reaped\n");
            break;
        }
        else {
            printf("Reaped a child %d\n",pid);
            if (WIFEXITED(wstatus)) {
                printf("exited, status=%d\n", WEXITSTATUS(wstatus));
            } else if (WIFSIGNALED(wstatus)) {
                printf("killed by signal %d\n", WTERMSIG(wstatus));
            } else if (WIFSTOPPED(wstatus)) {
                printf("stopped by signal %d\n", WSTOPSIG(wstatus));
            } else if (WIFCONTINUED(wstatus)) {
                printf("continued\n");
            }
        }
    } while (1);
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
		sleep(5);
        printf("Client 1 exiting\n");
        fflush(stdout);
        exit(11);
	}
    ret = fork();
    if (ret == 0) {
        printf("I am child 2!! ret=%d pid=%d ppid=%d\n",
               ret, getpid(), getppid());
        sleep(15);
        printf("Client 2 exiting\n");
        fflush(stdout);
        exit(12);
    }
    ret = fork();
    if (ret == 0) {
        printf("I am child 3!! ret=%d pid=%d ppid=%d\n",
               ret, getpid(), getppid());
        sleep(1);
        printf("Client 3 exiting\n");
        fflush(stdout);
        exit(13);
    }

    
    while (1)
        sleep(10);
    printf("Exiting parent\n");
    
}
