#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

Lista* lst_cria() {
	return NULL;
}

int lst_vazia(Lista *l) {
	return (l == NULL);
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

Lista* lst_busca(Lista *l, int info) {
	Lista* lAux = l;
	
	while(lAux != NULL) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

void lst_imprime(Lista *l) {
	Lista* lAux = l;
	
	while(lAux != NULL) {
		printf("Info = %d\n", lAux->info);
		lAux = lAux->prox;
	}
}

Lista* lst_remove(Lista *l, int info) {
	if(l != NULL) {
		Lista* lAux = l->prox;
		
		if(l->info == info) {
			free(l);
			return lAux;
		}
		else {
			Lista* lAnt = l;
			
			while(lAux != NULL) {
				if(lAux->info == info) {
					lAnt->prox = lAux->prox;
					free(lAux);
					break;
				}
				else {
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

void lst_libera(Lista *l) {
	Lista* lProx;
	while(l != NULL) {
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

Lista* lst_insere_ordenado(Lista *l, int info) {
	Lista* lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	
	if(l == NULL) {
		lNew->prox = NULL;
		return lNew;
	}
	else if(l->info >= info){
		lNew->prox = l;
		return lNew;
	}
	else {
		Lista *lAnt = l;
		Lista *lProx = l->prox;
		
		while(lProx != NULL && lProx->info < info) {
			lAnt = lProx;
			lProx = lProx->prox;
		}
		
		lAnt->prox = lNew;
		lNew->prox = lProx;
		
		return l;
	}
}

//AP 1 2023.2 1 - a)
int qtd_menores_lista(Lista* l, int x) {
	Lista *lAux = l;
	int cont = 0;
	
	while(lAux != NULL) {
		if(lAux->info < x) {
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}

//AP 1 2023.2 1 - b)
Lista* insere_fim_lista(Lista *l, int x) {
	Lista *ln = (Lista*)malloc(sizeof(Lista));
	ln->info = x;
	ln->prox = NULL;
	
	Lista *lAux = l;
	
	while(lAux->prox != NULL)
		lAux = lAux->prox;
	lAux->prox = ln;
	
	return ln;
}

/*AP 1 2023.2 Segunda Chamada 1*/
Lista* insere_inicio_fim_lista(Lista *l, int x, int y) {
	Lista *lx = (Lista*)malloc(sizeof(Lista));
	lx->info = x;
	lx->prox = l;
	
	Lista *ly = (Lista*)malloc(sizeof(Lista));
	ly->info = y;
	Lista *lAux = l;
	
	while(lAux->prox != NULL)
		lAux = lAux->prox;
	lAux->prox = ly;
	ly->prox = NULL;
	
	return lx;
}
