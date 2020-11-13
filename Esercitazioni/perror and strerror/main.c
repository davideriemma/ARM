#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE * booby = fopen("THIS PATH DOES NOT EXIST", "r");
    char * the_error = "the error is";

    perror(the_error);
    printf("is it equal to \n%s: %s\n?\n", the_error, strerror(errno));

    return 0;
}