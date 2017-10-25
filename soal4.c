#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//int n[100];
int status;
 
void *faktorial (void *ptr){
        status=0;
        int x=strtol ((char*)ptr, NULL, 10);
        int hasil=1;
        for (int i=1;i<=x;i++){
                hasil = hasil*i;
        }
        printf("Hasil %d! = %d\n",x, hasil);
        status=1;
}
int main(int panjang, char* n[]){
        int err;
        pthread_t tid[panjang];
        int pos=1;
        while (pos<=panjang){
        status=0;
        err=pthread_create (&(tid[pos]), NULL, &faktorial, (void*)n[pos]);
        while (status!=1) {}
        pos++;
        }
        int x;
        for (x=1;x<=panjang;x++){
        pthread_join (tid[x], NULL);
        }
}
