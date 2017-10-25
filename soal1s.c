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

void lihat(){
	int a,b,c;
	//for(a=0;a<=
}
int xx=0;
int main(){
	int i,j=0,k=0,berapa;
	char temp[20],temp1[20];
	int shmid;
	key_t key = 4567;
	size_t size = 30;
	struct shm *shmdat[30];

	if((shmid = shmget(key,size,IPC_CREAT | 0666)) == -1)
	{
		printf("Errorn");
		return -1;
	}

	if((shmdat[0] = shmat(shmid,NULL,0)) == (struct shm*) -1)
	{
		printf("Errorn");
		return -1;
	}
	
	while(1){
	//shmdat.tanda=1;
	scanf("%s",&temp);
	if (strcmp(temp,"LIHAT")==0){
		scanf("%s",&temp1);
		lihat();
	}
	else if (strcmp(temp,"EXIT")==0) break;
	else {
		scanf("%d",&berapa);
		for(i=0;i<=xx;i++){
			if(strcmp(temp,shmdat[i]->senjata)==0){
				shmdat[i]->stok=shmdat[i]->stok+berapa;
			}
			else {
				strcpy(shmdat[xx]->senjata,temp);
				shmdat[xx]->stok=berapa;xx++;
			}
		}
	}
	}
	return 0;
}
