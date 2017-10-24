#include <pthread.h>
#include <stdio.h>
#include <string.h>

char input[2000];
char hehe[10];
char h3h3[1000];
char cari[20][20];
int banyaknya[1000];
pthread_t tid[1000];
typedef struct{
	char nama[20];
} nyari;
nyari orang[20];
typedef struct{
	char perkata[20];
} darifile;
darifile h2h2[2000];
int z,b=0,j=0,count=0;
void* caridong(void *arg){
	pthread_t id=pthread_self();
	while(count<=j){
		if(pthread_equal(id,tid[count])){
			for(z=0;z<=b;z++){
				if(orang[count].nama==h2h2[z].perkata){
					banyaknya[count]=banyaknya[count]+1;
				}
			}
		}
	}

}
int main(){
	int i=0,k=0,a=0,c=0;
	scanf("%s %[^\n]",&hehe,&input);
	FILE *novel;
        novel = fopen("novel.txt", "r");
        fscanf(novel,"%[^\n]",&h3h3);
	for(a=0;a<=strlen(h3h3);a++){
                h2h2[b].perkata[c]=h3h3[a];
                c++;
                if(input[a]==32){
                        //pthread_create(&(tid[j]),NULL,&caridong,NULL);
                        b=b+1;
                        c=0;
                        //printf("berhasil\n");
                }
        } 
	for(i=0;i<=strlen(input);i++){
		//cari[j][i]=input[i];
		orang[j].nama[k]=input[i];
		//printf("%c\n",orang[1].nama[k]);
		k++;
		if(input[i]==32){
			pthread_create(&(tid[j]),NULL,&caridong,NULL);
			j=j+1;
			k=0;
			printf("berhasil\n");
		}
	} 
	
	return 0;
}
