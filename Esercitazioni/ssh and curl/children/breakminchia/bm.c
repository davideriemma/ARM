#include <stdio.h>
#include <unistd.h>
#include "bm.h"

int bm(void * args)
{
    while(1)
    {
        puts("Hey Hey");
        sleep(SECONDS_TO_SLEEP);
    }
}