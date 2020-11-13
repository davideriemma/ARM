#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <curl/curl.h>

#define XML_RESPONSE_DIM 1024

typedef struct
{
    char today[XML_RESPONSE_DIM];
    char tomorrow[XML_RESPONSE_DIM];

} w_info;

/*"thread" functions*/
void child(CURL *, char *);
void parent(CURL *, char *);
size_t write_callback(char *ptr, size_t always_1, size_t actual_data_size, void *userdata); //used to store data in the structure

int main()
{
    /*puntatore alla memoria condivisa*/
    w_info * result;
    /*url of the get request*/
    char * today = "-";
    char * tomorrow = "-";
    /*initializes curl*/
    CURL * c = curl_easy_init();
    if(!c)
    {
        puts("Error creating the curl handle.");
    }
    else
    {
        /*initialize shared memory*/
        //key_t the_key = ftok("./main", 'd');
        int id_shm = shmget(IPC_PRIVATE, sizeof(w_info), IPC_CREAT); /*private perchè la memoria è condivisa solo tra il 
                                                                    padre ed il figlio, mentre ipc_create senza alcun controllo degli errori 
                                                                    è perchè sicuramente questa è la prima volta che la risorsa viene creata*/
        if(id_shm == -1)
        {
            perror("Error creating the semaphore");
        }
        else
        {
            /*attacca la memoria condivisa (la copia del puntatore tanto è condivisa tra il padre ed il figlio)*/
            result = (w_info *) shmat(id_shm, NULL, 0);
            /*controlliamo se l'attach è andato a buon fine*/
            if(result = (void *) -1 )
            {
                perror("Qualcosa è andato storto");
            }
            else
            {
                /*procedi con la creazione dei processi, che ora potranno utilizzare la memoria condivisa per scrivere i risultati*/
                pid_t fork_res = fork();

                if(fork_res == 0)
                {
                    child(c, today);
                }
                else if(fork_res > 0)
                {
                    parent(c, tomorrow);
                }
                else if(fork_res == -1)
                {
                    perror("Error creating the child process, exiting");
                }

                shmctl(id_shm, IPC_RMID, NULL); /*clean up the shared memory*/
            }
            
        }

        curl_easy_cleanup(c); //perform cleanup of the curl handle
    }

    return 0;
}

void child(CURL * c, char * w)
{
    /*TBD: scrivere codice child*/
    exit(EXIT_SUCCESS);
}

/*scrivere i dati nella stringa*/
size_t write_callback(char *ptr, size_t always_1, size_t actual_data_size, void *userdata)
{
    static int count = 1; //conta il numero di bytes scritti fin'ora
    char * res = (char *) userdata;

    /*TBD: scrivere coice scrittura nella memoria*/

    count++;
    return actual_data_size;
}
