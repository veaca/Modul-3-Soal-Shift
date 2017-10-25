#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char input[2000];
char hehe[10];
char h3h3[1000];
char cari[20][20];
int status=0;
int haha,banyaknya[1000];
pthread_t tid[10];
typedef struct{
	char nama[20];
} nyari;
nyari orang[20];
typedef struct{
	char perkata[20];
} darifile;
darifile h2h2[2000];
int z,r,t,b=0,j=0;
void* caridong(void *arg){
	pthread_t id=pthread_self();
		if(pthread_equal(id,tid[0])){
			status=0;
			for(z=0;z<=b;z++){
				if(strcmp(orang[0].nama,h2h2[z].perkata)==0){
					banyaknya[0]=banyaknya[0]+1;
				}
			}
			printf("%s : %d\n",orang[0].nama,banyaknya[0]);
			status=status+1;
		}
		if(pthread_equal(id,tid[1])){
                      while(status!=1){ }
                        for(r=0;r<=b;r++){
                                if(strcmp(orang[1].nama,h2h2[r].perkata)==0){
                                        banyaknya[1]=banyaknya[1]+1;
                                }
                        }
                        printf("%s : %d\n",orang[1].nama,banyaknya[1]);
                        
                        status=status+1;
                }
		if(pthread_equal(id,tid[2])){
                      while(status!=2){ }
                        for(t=0;t<=b;t++){
                                if(strcmp(orang[2].nama,h2h2[t].perkata)==0){
                                        banyaknya[2]=banyaknya[2]+1;
                                }
                        }
                        printf("%s : %d\n",orang[2].nama,banyaknya[2]);
                        
                        status=status+1;
                }
	

}
int main(){
	int i=0,k=0,a=0,c=0;
	scanf("%s %[^\n]",&hehe,&input);
	for(i=0;i<=strlen(input);i++){
                if(input[i]==32){
                        j=j+1;
                        k=0;
			continue;
                }
		orang[j].nama[k]=input[i];
		k++;
        }
	FILE *novel;
        novel = fopen("novel.txt", "r");
        fscanf(novel,"%[^\n]",&h3h3);
	for(a=0;a<=strlen(h3h3);a++){
                if(h3h3[a]==32){
                        b=b+1;
                        c=0;
			continue;
                }
		if(h3h3[a]==44) continue;
		if(h3h3[a]==46) continue;
		h2h2[b].perkata[c]=h3h3[a];
		c++;
        } 
	fclose(novel);

	for(haha=0;haha<=j;haha++){
		pthread_create(&(tid[haha]),NULL,&caridong,NULL);
	}
	pthread_join(tid[0], NULL);
     	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	return 0;
}
