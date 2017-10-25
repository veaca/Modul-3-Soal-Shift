#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

struct shm{
	char isi[max];
	char senjata[max];
	int stok;
};

int main(){
	int i,j=0,k=0;
	char temp[1000];
	int shmid;
	key_t key = 4567;
	size_t size = 30;
	struct shm *shmdat[30];

	if((shmid = shmget(key,size,IPC_CREAT | 0666)) == -1)
	{
		printf("Errorn");
		return -1;
	}

	if((shmdat[0] = shmat(shmid,NULL,0)) == (struct shm *) -1)
	{
		printf("Errorn");
		return -1;
	}

	return 0;
}
