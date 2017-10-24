#include <pthread.h>
#include <stdio.h>
#include <string.h>

char input[2000];
char hehe[10];
char cari[20][20];
typedef struct{
	char nama[20];
} nyari;
nyari orang[20];

void caridong(){
	

}
int main(){
	int i=0,j=0,k=0;
	scanf("%s %[^\n]",&hehe,&input);
	for(i=0;i<=strlen(input);i++){
		//cari[j][i]=input[i];
		orang[j].nama[k]=input[i];
		//printf("%c\n",orang[1].nama[k]);
		k++;
		if(input[i]==32){
			j=j+1;
			k=0;
			printf("berhasil\n");
		}
	} 
	//printf("%s \n",input);
	FILE *fp, *novel;
	novel = fopen("novel.txt", "r");
	char h3h3,nama[50];
	fscanf(novel,"%[^\n]",&input);
	printf("%s",input);

	//printf("%s\n",orang[0].nama);
	return 0;
}
