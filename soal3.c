#include <string.h>
#include <stdio.h>
//#include <pthread.h>

int main(){
	int lohan, kepiting;
	lohan = 100;
	kepiting = 100;

	while (1){
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
	}
}
