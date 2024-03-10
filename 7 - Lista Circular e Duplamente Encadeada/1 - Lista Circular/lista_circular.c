#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

struct lista_circ {
	int info;
	ListaCirc *prox;
};

ListaCirc* lst_circ_cria() {
	return NULL;
}

int lst_circ_vazia(ListaCirc *l) {
	return(l == NULL);
}

ListaCirc* lst_circ_insere(ListaCirc *l, int info) {
	ListaCirc* ln = (ListaCirc*)malloc(sizeof(ListaCirc));
	ln->info = info;
	
	if(l == NULL) {
		ln->prox = ln;
	}
	else {
		ln->prox = l->prox;
		l->prox = ln;
	}
	return ln;
}

ListaCirc* lst_circ_busca(ListaCirc *l, int info) {
	ListaCirc* lAux = l;
	
	while(lAux != l) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

void lst_circ_imprime(ListaCirc *l) {
	if(l != NULL) {
		ListaCirc* lAux = l;
		printf("Lista de elementos:\n");
		
		do {
			printf("Info = %d\n", lAux->info);
			lAux = lAux->prox;
		}while(l != lAux);
	}
}

ListaCirc* lst_circ_remove(ListaCirc *l, int info) {
	if(l != NULL) {
		ListaCirc* lAux = l->prox;
		
		if(l->info == info) {
			free(l);
			return lAux;
		}
		else {
			ListaCirc* lAnt = l;
			
			while(lAux != l) {
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

void lst_circ_libera(ListaCirc *l) {
	ListaCirc *lProx;
	while(lProx != l) {
		lProx = lProx->prox;
		free(l);
		l = lProx;
	}
}
