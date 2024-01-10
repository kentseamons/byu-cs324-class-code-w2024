#include <stdio.h>

/*
 * gcc -g -o argv argv.c
 */

// an equivalent definition for main
// int main ( int argc, char **argv) {

int main( int argc, char *argv[] )  {

    printf("Value of argc is %d\n",argc);
    printf("Address of argc is %p\n",&argc);
    
    for (int i=0; i<argc; i++) {
        
        printf("Argument %d: %s\n", i, argv[i]);
    }
}
