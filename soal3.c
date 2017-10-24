#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int stat_lohan;
int stat_kepiting;
int lohan =100;
int kepiting = 100;

void *MinusLohan (void *ptr){
	int i, length=10;
	while (stat_lohan==0){
	for (int i=0; i<=10; i++){
//		printf ("%d ", i);
		sleep(1);
	}
	lohan -= 15;
//	if (lohan<50) printf ("Lohan Lapar! Minta Makan Oi!\n");
	}
}
void *MinusKepiting (void *ptr){
	int i, length=20;
	while (stat_kepiting==0){
	for (int i=0;i<=length;i++) sleep (1);
	kepiting -= 10;
//	if (kepiting<50) printf ("Kepiting Lapar! Minta Makan Oi!\n");
	}
}


int main(){
//	int lohan, kepiting;
//	lohan = 100;
//	kepiting = 100;
	int err1, err2;
	pthread_t tid[3];
	stat_lohan=0;
	stat_kepiting=0;
	err1 = pthread_create (&(tid[1]), NULL, MinusLohan, NULL);
	err2 = pthread_create (&(tid[2]), NULL, MinusKepiting, NULL);
//	for (int i=1;i<=2;i++) pthread_join (tid[i],NULL);
	while (1){
		if (lohan<50) printf ("Lohan Lapar! Minta Makan Oi!\n");
		if (kepiting<50) printf ("Kepiting Lapar! Minta Makan Oi!\n");
		//err = pthread_create (&(tid[1]), NULL, MinusLohan, NULL);
		printf ("---Pilih fitur---\n1. Beri makan lohan \n2. Beri makan kepiting\n");
		printf ("3. Lihat status\n");
		printf ("Masukkan fitur (1/2/3)\n");
		int fitur;
		scanf ("%d", &fitur);
		if (fitur == 1) lohan += 10;
		else if (fitur == 2) kepiting += 10;
		else if (fitur == 3) {
			printf ("Lohan = %d\nKepiting =%d\n\n", lohan , kepiting);
		}
		if (lohan < 0 || kepiting < 0){
		stat_lohan=1;
		printf ("Game Selesai\n");
		break;
		}
	}
}
