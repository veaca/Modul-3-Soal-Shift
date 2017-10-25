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
//	printf("berhasil caridong\n");
		if(pthread_equal(id,tid[0])){
			status=0;
//			printf("berhasil pthread count 0\n");
			for(z=0;z<=b;z++){
//				printf("berhasil masuk z %d loop\n",z);
				if(strcmp(orang[0].nama,h2h2[z].perkata)==0){
					banyaknya[0]=banyaknya[0]+1;
//					printf("Berhasil masuk banyak kata%d \n",banyaknya[0]);
				}
			}
			printf("%s : %d\n",orang[0].nama,banyaknya[0]);
			status=status+1;
		}
		if(pthread_equal(id,tid[1])){
                      while(status!=1){ }
  //                    printf("berhasil pthread count 1\n");
                        for(r=0;r<=b;r++){
 //                             printf("berhasil masuk r %d loop\n",r);
                                if(strcmp(orang[1].nama,h2h2[r].perkata)==0){
                                        banyaknya[1]=banyaknya[1]+1;
   //                                   printf("Berhasil masuk banyak kata%d \n",banyaknya[1]);
                                }
                        }
                        printf("%s : %d\n",orang[1].nama,banyaknya[1]);
                        
                        status=status+1;
                }
		if(pthread_equal(id,tid[2])){
                      while(status!=2){ }
     //                 printf("berhasil pthread count 2\n");
                        for(t=0;t<=b;t++){
       //                       printf("berhasil masuk t %d loop\n",t);
                                if(strcmp(orang[2].nama,h2h2[t].perkata)==0){
                                        banyaknya[2]=banyaknya[2]+1;
         //                             printf("Berhasil masuk banyak kata%d \n",banyaknya[2]);
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
                //cari[j][i]=input[i];
               // orang[j].nama[k]=input[i];
//                printf("%c\n",orang[j].nama[k]);
               // k++;
                if(input[i]==32){
//                      printf("coba\n");
//                        pthread_create(&(tid[j]),NULL,&caridong,NULL);
                        j=j+1;
                        k=0;
			continue;
//                      printf("berhasil\n");
                }
		orang[j].nama[k]=input[i];
		k++;
        }
	FILE *novel;
        novel = fopen("novel.txt", "r");
        fscanf(novel,"%[^\n]",&h3h3);
	for(a=0;a<=strlen(h3h3);a++){
                //h2h2[b].perkata[c]=h3h3[a];
                //c++;
                if(h3h3[a]==32){
                        //pthread_create(&(tid[j]),NULL,&caridong,NULL);
                        b=b+1;
                        c=0;
			continue;
  //                      printf("berhasil\n");
                }
		if(h3h3[a]==44) continue;
		h2h2[b].perkata[c]=h3h3[a];
		c++;
        } 
	fclose(novel);

	for(haha=0;haha<=j;haha++){
//		printf("%d",haha);
		pthread_create(&(tid[haha]),NULL,&caridong,NULL);
	}
	pthread_join(tid[0], NULL);
     	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
/*	for(haha=0;haha<=b;haha++){
		printf("%s\n",orang[0].nama);
		printf("%s ",h2h2[haha].perkata);
                if(strcmp(orang[0].nama,h2h2[haha].perkata)==0){
                        banyaknya[count]=banyaknya[count]+1;
                        printf("Berhasil masuk banyak kata%d \n",banyaknya[count]);
                }
                //printf("%d",banyaknya[count]);
        }
*/	return 0;
}
