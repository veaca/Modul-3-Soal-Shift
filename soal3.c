#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int lohan =100;
int kepiting = 100;

void *MinusLohan (void *ptr){
	int i, length=10;
	for (int i=0; i<=10; i++){
//		printf ("%d ", i);
		sleep(1);
	}
	lohan -= 15;
}

int main(){
//	int lohan, kepiting;
//	lohan = 100;
//	kepiting = 100;
	int err;
	pthread_t tid[3];
//	while (lohan >0 && kepiting >0)err = pthread_create (&(tid[1]), NULL, MinusLohan, NULL);
	while (lohan > 0 && kepiting > 0){
		err = pthread_create (&(tid[1]), NULL, MinusLohan, NULL);
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
		printf ("Game Selesai\n");
		break;
		}
	}
}
