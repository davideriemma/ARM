#include <unistd.h>
#include <stdio.h>

#define SLEEP_SECONDS 2

/**
 * Author: Davide Riemma
 * Description: il programma prosegue indefinitamente rompendo la minchia letteralmente ogni due secondi
*/

int main()
{
    while(1)
    {
        puts("Hey Hey");
        sleep(SLEEP_SECONDS);
    }
    return 0;
}