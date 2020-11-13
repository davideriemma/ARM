#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

/*using a symvar to avoid all the burden with the compiler when using enums in assembly*/
#define true 1
#define false 0 

extern int increment_by_1(void * location);
extern int increment_by_2(void * location);

int main()
{

	/*initialize shared memory*/
	int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT);

	if(shm_id == -1)
	{
		perror("Error creating the shared resource");
	}
	else
	{
		int * res = (int *) smhat(shm_id, NULL, 0);
		if(res == (void *) -1)
		{
			perror("Error attacching the shared resource");
		}
		else
		{
			int res1, res2;
			extern int flag[2];
			flag[0] = false;
		        flag[1] = false;	
			/*create and execute the threads*/
			pthread_t t1, t2;
			pthread_create(&t1, NULL, increment_by_1, (void *) res);
			pthread_create(&t2, NULL, increment_by_2, (void *) res);

			pthread_join(t1, (void *) &res1);
			pthread_join(t2, (void *) &res2);

			/*show the result of execution (should be 3 increment by one and 2 by 2)*/
			printf("result is: %d.\n P0 has spent %d iteration waiting\n P1 has spent %d iteration waiting.\n", *res, res1, res2);
			/*now release the resource*/
			shmctl(shm_id, IPC_RMID, NULL);
		}
	}

	return 0;
}
