#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

char pemain1[100];
char pemain2[100];
int kotak1[16];
int kotak2[16];
int tebakan1[16];
int tebakan2[16];
int poin1=0;
int poin2=0;

void *gerak1 (void *ptr){
	int jumlah;
	printf ("Masukkan jumlah ranjau yang ingin dipasang: ");
	scanf ("%d", &jumlah);
	for (int i=1;i<=4;i++){
		int pos;
		printf ("Ranjau %d: ", i);
		scanf ("%d", &pos);
		kotak1[pos]=1;
	}
}

void *gerak2 (void *ptr){
        int jumlah;
        printf ("Masukkan jumlah ranjau yang ingin dipasang: ");
        scanf ("%d", &jumlah);
        for (int i=1;i<=4;i++){
                int pos;
                printf ("Ranjau %d: ", i);
                scanf ("%d", &pos);
                kotak2[pos]=1;
        }
}

void *tebak1 (void *ptr){
        for (int i=1;i<=4;i++){
                int pos;
                printf ("Tebakan %d: ", i);
                scanf ("%d", &pos);
                tebakan1[pos]=1;
        }
}

void *tebak2 (void *ptr){
        for (int i=1;i<=4;i++){
                int pos;
                printf ("Tebakan %d: ", i);
                scanf ("%d", &pos);
                tebakan2[pos]=1;
        }
}

void cek1(){
	for (int i=1;i<=16;i++){
		if (tebakan2[i]==1 && kotak1[i]==1) poin1++;
		else if (tebakan2[i]==1 && kotak1[i]!=1) poin2++;
	}
	for (int i=1;i<=16;i++) tebakan2[i]=0;
}

void cek2(){
        for (int i=1;i<=16;i++){
                if (tebakan1[i]==1 && kotak2[i]==1) poin2++;
                else if (tebakan1[i]==1 && kotak2[i]!=1) poin1++;
        }
        for (int i=1;i<=16;i++) tebakan1[i]=0;
}


int main(){
	int move1, guess1,move2,guess2, gerak=1;
	printf ("Masukkan nama pemain 1: ");
	scanf ("%s",pemain1);
        printf ("Masukkan nama pemain 2: ");
	scanf ("%s",pemain2);
	pthread_t tid[4];
	while (1){
		if (gerak==1){
			move1 = pthread_create (&tid[1], NULL, gerak1, NULL);
			guess2 = pthread_create (&tid[4], NULL, tebak2, NULL);
			pthread_join (tid[1], NULL);
			pthread_join (tid[4], NULL);
			cek1();
		gerak=2;
		}
		if (gerak==2){
                        move2 = pthread_create (&tid[3], NULL, gerak1, NULL);
                        guess1 = pthread_create (&tid[2], NULL, tebak2, NULL);
                        pthread_join (tid[3], NULL);
                        pthread_join (tid[2], NULL);
			cek2();
                gerak=1;
                }
/*		char input[100];
		scanf ("%s",input);
		if (strcmp("Cek", input) == 0) printf ("Poin %s : %d\nPoin %s : %d", pemain1, poin1, pemain2, poin2); */
	}
}
