#include <stdio.h>
#include <stdlib.h>

/*
 * $ gcc -o getenv getenv.c
 * $ ./getenv
 * $ ./getenv BYU
 * $ BYU=cougars ./getenv BYU
 * $ ./getenv BYU
 * $ export BYU=cougars
 * $ env
 * $ ./getenv BYU
 */

int main( int argc, char *argv[] )  {

   // Check for argument specifying an environment variable name
   if (argc < 2) {
       printf("Usage: ./getenv <environment variable>\n");
       exit(0);
   }

   char *envvar = NULL;
   // Get environment variable value
   envvar = getenv(argv[1]);

   if (envvar == NULL)
       printf("Environment variable not defined\n");
   else
       printf("Environment variable %s has value %s\n",argv[1],envvar);

   // Where are environment variable values located? Above the stack
   // printf("Pointer to the environment variable value: %p\n", XX);
   // What variable goes in XX above? envvar or &envvar?
}
