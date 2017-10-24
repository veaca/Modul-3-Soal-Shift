#include <pthread.h>
#include <stdio.h>
int n[100];
int status;

void *faktorial (void *ptr){
	status=0;
	int *x=ptr;
	int hasil=1;
//	status =1;
//	printf ("%d\n", *x);
	for (int i=1;i<=n[*x];i++){
		hasil = hasil*i;
	}
	printf("%d\n", hasil);
	status=1;
	return 0;
}

int main(){
	int lebar;
	printf ("Masukkan lebar: ");
	scanf ("%d", &lebar);
//	int n[lebar];
	printf ("Masukkan angka: ");
	for (int i=1;i<=lebar;i++){
	scanf ("%d", &n[i]);
	}
	int err;
	pthread_t tid[lebar+1];
	int pos=1;
	while (pos<=lebar){
	status=0;
	printf ("%d: ", pos);
	err=pthread_create (&(tid[pos]), NULL, faktorial, (void*)&pos);
//	printf ("faktorialnya: %d\n", faktorial (n));
	while (status!=1) {}
	pos++;
	}

	for (int x=1;x<=lebar;x++){
	pthread_join (tid[x], NULL);
	}
}
