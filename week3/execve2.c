 /* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { NULL, "hello", "world", NULL };
    char *newenviron[] = { NULL };
    
    fprintf(stderr, "execve2: argc is %d\n", argc);
    
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    */
    
    newargv[0] = argv[1];

    //execve(argv[1], newargv, newenviron);
    execve(argv[1], &argv[1], newenviron);
    perror("execve");   /* execve() returns only on error */
    exit(EXIT_FAILURE);
}
