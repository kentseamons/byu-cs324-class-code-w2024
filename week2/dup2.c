//#include <stdio.h>
#include <unistd.h>

/*
 * Use dup2 for I/O redirection from a C program
 * See man dup2
 * 
 */

int main(int argc, char *argv[]) {

    // print message to stdout
    fprintf(stdout,"Hello1, STDOUT\n");

    // open file tmp.txt
    // redirect stdout to file
    FILE *myfile = fopen("tmp.txt","w");

    // Same as ./dup2 > tmp.txt
    dup2(fileno(myfile),1);
    
    // print message to stdout
    fprintf(stdout,"Hello2, STDOUT\n");
}
