#include <stdio.h>

/*
 * gcc -g -o argv argv.c
 */

// an equivalent definition for main function using char **argv
// int main ( int argc, char **argv) {

int main( int argc, char *argv[] )  {

    printf("Value of argc is %d\n",argc);
    printf("Address of argc is %p\n\n",&argc);

    printf("Value of argv is %p\n",argv);
    printf("Address of argv is %p\n",&argv);
    
    for (int i=0; i<argc; i++) {
        printf("Address of argv[%d]: %p\n", i, &argv[i]);
        printf("Value stored in argv[%d]: %p - this is a pointer stored in the argv array\n", i, argv[i]);
        printf("String referenced by argv[%d]: %s\n", i, argv[i]);
    }
}
