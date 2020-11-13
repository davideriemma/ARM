#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "parent_process.h"
#include "child_process.h"

int main()
{

    pid_t the_pid = fork();

    if(the_pid != 0)
    {
        parent_process("xilofono la si do re mi"); //rip off of execl
    }
    else if(the_pid == 0)
    {
        child_process("10000"); //rip off of execl
    }
    else if(the_pid == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}