 /* execve.c - from man execve page */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { NULL, "hello", "world", NULL };
    char *newenviron[] = { NULL };
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    newargv[0] = argv[1];

    execve(argv[1], newargv, newenviron);
    
    perror("execve");   /* execve() returns only on error */
    exit(EXIT_FAILURE);
}
