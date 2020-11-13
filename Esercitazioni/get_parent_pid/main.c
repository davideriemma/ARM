#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{

    pid_t parent_pid, my_pid;

    /*get the current process pid*/
    my_pid = getpid(); //minchia, this function is always succesful. Glorioso!
    parent_pid = getppid(); //again, always succesful.

    printf("The parent process id id %d and you will never no its name.\n", parent_pid);
    printf("Whereas my process id i s %d and you already know my name.\n", my_pid);

    return 0;
}