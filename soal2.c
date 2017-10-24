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

int main(){
	printf ("Masukkan nama pemain 1: ");
	scanf ("%s",pemain1);
        printf ("Masukkan nama pemain 2: ");
	scanf ("%s",pemain2);
	while (1){
		char input[100];
		scanf ("%s",input);
		if (strcmp("Cek", input) == 0) printf ("Poin %s : %d\nPoin %s : %d", pemain1, poin1, pemain2, poin2); 
	}
}
