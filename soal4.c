#include <stdio.h>

int faktorial (int n){
	int hasil=1;
	for (int i=1;i<=n;i++){
		hasil = hasil*i;
	}
	return hasil;
}

int main(){
	int n;
	printf ("Masukkan angka: ");
	scanf ("%d", &n);
	printf ("faktorialnya: %d\n", faktorial (n));

}
