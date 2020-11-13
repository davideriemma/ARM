#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include "children/children.h"

int main()
{

    /*argomenti dei figli*/

    pswho_args ps = {"localhost", "davide", "%HOME/tempKey"};

    /*vettore dei figli: il primo è bm, il secondo pswho*/
    extern int (*threads[])(void *);

    /*vettore degli argomenti*/
    void * args[] = {NULL, (void *) &ps};

    /*pid del figlio che rompe all'infinito*/
    pid_t infinite_child, fork_res;

#ifdef DEBUG
    printf("DEBUG: size of the vector of pointers (*threads): %ud", sizeof(*threads));
#endif

    for(int i = 0; i < sizeof(*threads); ++i)
    {
        fork_res = fork();
        if(fork_res == 0) //siamo nel figlio
        {
            threads[i](args[i]); //esegue la sua funzione appropriata
        }
        else if(fork_res > 0 && !i)
        {
            infinite_child = fork_res; //conserva il valore del figlio birichino, che dobbiamo ammazzare a fine programma
        }
        else if(fork_res < 0)
        {
            perror("Error Spawning Child");
        }
        
    }

    /*ora aspettiamo la loro terminazione (ci sincronizziamo con il genitore)*/
    for(int i = 0; i < sizeof(*threads) - 1; ++i)
    {
        wait(NULL); //don't care about how they exit right now
    }

    /*ammazza il figlio monello*/
    kill(infinite_child, SIGKILL);
    /*aspetta anche che il figlio monello morto ritorni*/
    waitpid(infinite_child, NULL, WNOHANG);

    /*TBD: codice per gestire che il segnale ricevuto dal figlio sia effettivamente SIGKILL, e che non abbia fatto danni durante la sua esecuzione*/

    return 0;
}