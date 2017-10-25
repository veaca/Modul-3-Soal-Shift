#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

int xx=0,*jumlah;
struct dagang{
	char senjata[8];
}
struct dagang nama[6];
strcpy(nama[0].senjata,"MP4A1");
strcpy(nama[1].senjata,"PM2-V1");
strcpy(nama[2].senjata,"SPR-3");
strcpy(nama[3].senjata,"SS2-V5");
strcpy(nama[4].senjata,"SPG1-V3");
strcpy(nama[5].senjata,"MINE");

void lihat(){
	int a;
	for(a=0;a<6;a++){
		printf("%s %d\n",nama[a].senjata,total[a]);
	}
}
void menu(){
	system("clear");
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
	while(1){
	//shmdat.tanda=1;
	menu();
	scanf("%s",&temp);
	if (strcmp(temp,"LIHAT")==0){
		scanf("%s",&temp1);
		printf("masuk lihat\n");
		lihat();
	}
	else if (strcmp(temp,"EXIT")==0) break;
	else if (strcmp(temp,"MP4A1"){ 
		scanf("%d",&berapa);
		total[0]=total[0]+berapa;
	}
	else if (strcmp(temp,"PM2-V1"){ 
                scanf("%d",&berapa);
                total[1]=total[1]+berapa;
        }
	else if (strcmp(temp,"SPR-3"){ 
                scanf("%d",&berapa);
                total[2]=total[2]+berapa;
        }
	else if (strcmp(temp,"SS2-V5"){ 
                scanf("%d",&berapa);
                total[3]=total[3]+berapa;
        }
	else if (strcmp(temp,"SPG1-V3"){ 
                scanf("%d",&berapa);
                total[4]=total[4]+berapa;
        }
	else if (strcmp(temp,"MINE"){ 
                scanf("%d",&berapa);
                total[5]=total[5]+berapa;
        }
	}
	}
	return 0;
}
