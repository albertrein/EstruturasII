#include <stdio.h>
#include <stdlib.h>

typedef struct ARVORE{
	int valor;
	struct ARVORE *esq;
	struct ARVORE *dir;
} TREE;

int insertNo(TREE *raiz, TREE *no){
	if(raiz == NULL)
		return 0;

	if(raiz->valor == no->valor)
}

int cadastraNo(TREE *noCadastra){
	printf("Digite um valor de cadastro: ");
	scanf("%i",&noCadastra->valor);
	noCadastra->esq	= NULL;
	noCadastra->dir = NULL;
	return noCadastra->valor;
}

int main(){
	TREE *raiz, *no;
	int fluxo = 0;
	raiz = NULL;
	do{
		no = (TREE *) malloc(sizeof(TREE));
		fluxo = cadastraNo(no);
		if(raiz == NULL){
			raiz = no;
			continue;
		}
		insertNo(raiz, no);
	}while(fluxo == 0);




	return (0); //ENDS
}