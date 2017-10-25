#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

int *jumlah;

void lihat(){
	int a;
	if(jumlah[0]>=0) printf("MP4A1 : %d\n",jumlah[0]);
	if(jumlah[1]>=0) printf("PM2-V1 : %d\n",jumlah[1]);
	if(jumlah[2]>=0) printf("SPR-3 : %d\n",jumlah[2]);
	if(jumlah[3]>=0) printf("SS2-V5 : %d\n",jumlah[3]);
	if(jumlah[4]>=0) printf("SPG1-V3 : %d\n",jumlah[4]);
	if(jumlah[5]>=0) printf("MINE : %d\n",jumlah[5]);

}
void menu(){
	printf("---MENU---\n");
	printf("1.LIHAT STOK\n");
	printf("2.TAMBAH STOK : [nama barang] [banyaknya]\n");
}
int main(){
	int i,j=0,k=0,berapa;
	char temp[20],temp1[20],senjata[8];
	int shmid;
	key_t key = 4567;
	size_t size = 30;

	if((shmid = shmget(key,size,IPC_CREAT | 0666)) == -1)
	{
		printf("Errorn");
		return -1;
	}
	
	jumlah = shmat(shmid,NULL,0);
//	for(i=0;i<6;i++) jumlah[i]=0;
	while(1){
		menu();
		scanf("%s",&temp);
		if (strcmp(temp,"LIHAT")==0){
			scanf("%s",&temp1);
	//		printf("masuk lihat\n");
			lihat();
		}
		else if (strcmp(temp,"EXIT")==0) break;
		else if (strcmp(temp,"MP4A1")==0){ 
			scanf("%d",&berapa);
			if((jumlah[0]-berapa)<0) printf("Barang di stock tidak cukup\n");
			else jumlah[0]=jumlah[0]-berapa;
		}
		else if (strcmp(temp,"PM2-V1")==0){ 
                	scanf("%d",&berapa);
			if((jumlah[1]-berapa)<0) printf("Barang di stock tidak cukup\n");
                        else
                	jumlah[1]=jumlah[1]-berapa;
        	}
		else if (strcmp(temp,"SPR-3")==0){ 
                	scanf("%d",&berapa);
			if((jumlah[2]-berapa)<0) printf("Barang di stock tidak cukup\n");
                        else
                	jumlah[2]=jumlah[2]-berapa;
        	}
		else if (strcmp(temp,"SS2-V5")==0){ 
                	scanf("%d",&berapa);
			if((jumlah[0]-berapa)<0) printf("Barang di stock tidak cukup\n");
                        else
                	jumlah[3]=jumlah[3]-berapa;
        	}
		else if (strcmp(temp,"SPG1-V3")==0){ 
                	scanf("%d",&berapa);
			if((jumlah[4]-berapa)<0) printf("Barang di stock tidak cukup\n");
                        else
                	jumlah[4]=jumlah[4]-berapa;
        	}
		else if (strcmp(temp,"MINE")==0){ 
                	scanf("%d",&berapa);
			if((jumlah[5]-berapa)<0) printf("Barang di stock tidak cukup\n");
                        else
                	jumlah[5]=jumlah[5]-berapa;
        	}
		else if(strcmp(temp,"MENU")==0) menu();
		else{
			printf("INPUT SALAH\n");
			printf("KETIK MENU BILA BINGUNG\n");
		}
	}
	return 0;
}
