#include <stdlib.h>
#include <stdio.h>

// Use fprintf to print output to different streams

// Redirect the output somewhere other than the terminal
// How do each of the following behave?
//   ./redirect > outfile
//   ./redirect >> outfile
//   ./redirect 2> /dev/null
//   ./redirect 2> outfile
//   ./redirect  > outfile 2>&1
//   ./redirect 2> outfile 1>&2
//   ./redirect &> outfile

// The ordering changes when both stdout and stderr are redirected to a file
// Use stdbuf -o0 <command> to force unbuffered


int main(){
    fprintf(stdout, "Line 1: output to stdout\n");
    fprintf(stdout, "Line 2: output to stdout\n");
    fprintf(stdout, "Line 3: output to stdout\n");
    
    fprintf(stderr, "Line 4: output to stderr\n");
    fprintf(stderr, "Line 5: output to stderr\n");
    fprintf(stderr, "Line 6: output to stderr\n");
    
    fprintf(stdout, "Line 7: output to stdout\n");
    fprintf(stdout, "Line 8: output to stdout\n");
    fprintf(stdout, "Line 9: output to stdout\n");
    fflush(stdout);
    return 0;
}

