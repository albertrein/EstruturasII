#define LINUX
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../tempo/tempo.h"

int alimentaVETAleatorio (int *v, int t){

	int i;
	int MAX=20000000; // seria de -20000000 a 20000000
	
	for (i = 0; i < t; i++) {
		v[i] = (rand() % (MAX+MAX)) - MAX;
	}
	return(i);
}

int ordenaVetor(int *vet, int tamanho){
	int aux1;
	int i, j;
	for(i = 0; i < tamanho; i++){
		aux1 = vet[i];
		for(j = 0; j < tamanho; j++){
			if(vet[j] > vet[i]){
				vet[i] = vet[j];
				vet[j] = aux1;				
			}
		}
	}
	return(i);
}

int selectSort(int *v, int tam){
	int menor, aux;
	int i, j;

	for(i = 0; i < tam; i++){
		menor = v[i];
		for(j = i; j < tam; j++){
			if(v[j] < menor){
				aux = v[j];
				v[j] = menor;
				menor = aux;
			}
		}
		v[i] = menor;
	}
}

int buscaBinaria(int *c, int tam, int find){
	int i = 0, j, posic;
	posic = tam - 1;

	while(i <= posic){
		j = (i + posic) /2;
		if(find == c[j]){
			printf("Encontrado\n");
			return 1;
		}else if(find < c[j]){
			posic = j - 1;
		}else{
			i = j + 1;
		}
	}
	printf("Nao encontrado\n");
	return 1;
}


int encontrarValor(int valor, int *vet, int tam){
	int i, y;
	y = (int) tam/2;

	if(valor < vet[y]){
		for(i=0; i<y; i++){
			if(valor == vet[i]){
				return 1;
			}
		}		
	}else if(valor > vet[y]){
		for(i=y; i<tam; i++){
			if(valor == vet[i]){
				return 1;
			}
		}
	}else{
		return 1;
	}

	return 0;

}

int imprimeVetor(int *v, int tam){
	int i = 0;
	printf("*************************\n");
	for(;i<tam;i++){
		printf("* %i *\n",v[i]);
	}
	printf("*************************\n");
}

int main (int argc, char *argv[]){
	int *vetor;
	int tam, val, i;
	char go;	

	if (argc!=2){
		printf("Erro. Precisa passar o tamanho do vetor\n");
		return(1);
	}
	tam = atoi(argv[1]);
	
	vetor = (int *) malloc(tam * sizeof(int));
	if (vetor == NULL) {
		fprintf(stderr, "ERRO ao tentar alocar %d inteiros\n", tam);
		return(2);
	}

	srand(time(NULL));
	alimentaVETAleatorio (vetor, tam);
	
	printf("Começar?");
	scanf("%c",&go);
	printf("GO ...\n");
	//ordenaVetor(vetor, tam);
	selectSort(vetor, tam);
	printf("Vetor Ordenado!\n\n");
	
	printf("*** Deseja imprimir o vetor? s ou n ***\n");
	scanf("%c",&go);
	if(go == 's'){
		imprimeVetor(vetor, tam);
	}

	printf("Digite um valor para buscar\n");
	scanf("%i",&val);

	buscaBinaria(vetor, tam, val);

	free(vetor);
}