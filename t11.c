#define LINUX // ou nao
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int alimentaVETAleatorio (int *v, int t){

	int i;
	int MAX=20000000; // seria de -20000000 a 20000000
	
	for (i = 0; i < t; i++) {
		v[i] = (rand() % (MAX+MAX)) - MAX;
	}
	return(i);
}

int ordenaVetor(int *vet, int tamanho){ //Super SLOW
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

int main (int argc, char *argv[]){
	int *vetor;
	int tam, val;
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
	printf("......\n");
	ordenaVetor(vetor, tam);
	printf("Vetor Ordenado!\n\n");
	printf("Digite um valor para buscar\n");
	scanf("%i",&val);
	if(encontrarValor(val, vetor, tam) == 1){
		printf("Encontrado\n");
	}else{
		printf("Ñ Encontrado\n");
	}

	free(vetor);
}