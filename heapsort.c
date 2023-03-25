#include <stdio.h>
#include <stdlib.h>

void criaHeap(int *raiz, int i, int f);
void heapsort(int *raiz, int n);

int main(){

    int vetor[10] = {5,2,7,8,10,6,1,4,9,3};
	heapsort(vetor,10);
	for(int i = 0; i < 10; i++){
		printf("%i ", vetor[i]);
	}
    printf("\n");

    return 0;
}

void criaHeap(int *raiz, int i, int f){
    int aux = raiz[i], j=i*2+1;
    
    while(j <= f){
        if(j<f){
            if(raiz[j]<raiz[j+1]){
                j = j+1;
            }
        }
        if(aux<raiz[j]){
            raiz[i] = raiz[j];
            i = j;
            j = 2*i+1;
        }else{
            j=f+1;
        }
    }
    raiz[i] = aux;
}

void heapsort(int *raiz, int n){
    int aux;

    for(int i=(n-1)/2; i>=0; i--){
        criaHeap(raiz, i, n-1);
    }
    for(int i=n-1; i>=1; i--){
        aux = raiz[0];
        raiz[0] = raiz[i];
        raiz[i] = aux;
        criaHeap(raiz, 0, i-1);
    }
}