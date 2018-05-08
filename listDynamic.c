/*---------------------------------------------------------------------
Autor: Wylkson
Data início:05/05/2018
Data encerramento:06/05/2018
------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
Descricao: Utilize as informações a seguir para criar um algoritmo de lista dinâmica encadeado por ponteiros(endereços de memórias).
------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
	int dado;
	struct Elemento *prox;
}Elemento;

typedef struct lista{
	struct Elemento *final;
}Lista;

void criaListaVazia (Lista *l){
	l->final = NULL;
	printf("Lista criada com sucesso \n");
}

void insereElementos(Lista *l, Elemento *elem){
	if(l->final == NULL){
		elem->dado = 10;
		elem->prox = NULL;
		l->final = elem;
		printf("List final: %d\n\n",l->final);
		printf("Atual dado origem: %d\n\n",elem->dado);
		printf("Atual Element: %d\n\n",elem);
		printf("Lista vazia, elemento inserido com sucesso \n");
		printf("\n----------------------------------------------------------\n");
	}else{
		Elemento *atual = l->final;
		printf("List final: %d\n\n",l->final);
		printf("Atual Sem final: %d\n\n",atual);
		printf("Atual: %d\n\n",atual->dado);
		printf("Atual dado origem: %d\n\n",elem->dado);
		printf("Atual Element: %d\n\n",elem);
		atual->prox = elem;
		elem->dado = 20;
		elem->prox = NULL;
		l->final = elem;
		printf("\nNovo elemento inserido");
		printf("\n----------------------------------------------------------\n");
	}
}

void main(){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	criaListaVazia(l);
	Elemento *e = (Elemento*)malloc(sizeof(Elemento));
	Elemento *seg = (Elemento*)malloc(sizeof(Elemento));
	Elemento *terc = (Elemento*)malloc(sizeof(Elemento));
	insereElementos(l,e);
	insereElementos(l,seg);
	insereElementos(l,terc);
}

