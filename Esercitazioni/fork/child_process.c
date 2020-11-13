#include "child_process.h"
#include <stdlib.h>
#include <stdio.h>

void child_process(char * args)
{

    for(int i = 0; i < atol(args); ++i)
    {
        puts("\n\n\n\n\n\n");
    }

    return;
}