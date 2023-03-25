#include <stdio.h>
#include <stdlib.h>

void criaHeap(int *vetor, int i, int f);
void heapsort(int *vetor, int n);

int main(){

    int vetor[10] = {4,1,3,2,16,9,10,14,8,7};
	heapsort(vetor,10);
	for(int i = 0; i < 10; i++){
		printf("%i ", vetor[i]);
	}
    printf("\n");

    return 0;
}


void heapsort(int *vetor, int n){
    int aux;

    for(int i=(n-1)/2; i>=0; i--){
        criaHeap(vetor, i, n-1);
    }
    for(int i=n-1; i>=1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1);
    }
}

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i], j=i*2+1;
    
    while(j <= f){
        if(j<f){
            if(vetor[j]<vetor[j+1]){ //verifica qual dos filhos é maior
                j = j+1;
            }
        }
        if(aux<vetor[j]){ //verifica se o pai é menor que o filho
            vetor[i] = vetor[j];
            i = j;
            j = 2*i+1;
        }else{
            j=f+1;
        }
    }
    vetor[i] = aux;
}