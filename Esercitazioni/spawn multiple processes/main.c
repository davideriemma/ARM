#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "children.h"

int main()
{

    /**
     * data for the children
     * TBD: aggiungere correttamente gli argomenti da passare ai due processi
    */
   gpp_args gpp_child_args = {NULL, NULL};
   sqlite_cf_args sqlite_child_args = {NULL, NULL};

   /*end data*/

    extern int (*threads[])(void*); /*children to execute*/
    void * children_args[] = {NULL, (void *) &gpp_child_args, (void *) &sqlite_child_args}; /*arguments to pass to the children*/

    pid_t infinite_child, fork_result = fork();
    int infinite_child_status;
    for(int i = 0; i < CHILDREN_NUM; ++i)
    {
        if(fork_result == 0) /*child code*/
        {
            threads[i](children_args[i]);
        }
        /*code to handle the first and infinite-loop process*/
        if(fork_result > 0 && !i)
        {
            infinite_child = fork_result;
        }
        /*end code*/
    }

    /*now wait for their termination. Please, note that we don't care about the order in which the children terminate*/
    for(int i = 0; i < CHILDREN_NUM - 1; ++i) //one of them would be nasty!
    {
        wait(NULL); /*we pass null because we wouldn't be able to tell which is the child who terminates*/
    }

    if(!kill(infinite_child, SIGKILL))
    {
        perror("Error killing process, a zombie is alive");
    }
    else
    {
        waitpid(infinite_child, &infinite_child_status, WNOHANG);
        if(WIFSIGNALED(infinite_child_status))
        {
            printf("Processo terminato a causa di: %d", WTERMSIG(infinite_child_status));
        }
    }
    

    return 0;
}