#include <stdio.h>
#include <stdlib.h>
#include "lista_dupl_encadeada.h"

struct lista_dupl {
	int info;
	ListaDupl *prox;
	ListaDupl *ant;
};

ListaDupl* lst_dupl_cria() {
	return NULL;
}

int lst_dupl_vazia(ListaDupl *l) {
	return l == NULL;
}

ListaDupl* lst_dupl_insere(ListaDupl *l, int info) {
	ListaDupl *ln = (ListaDupl*)malloc(sizeof(ListaDupl));
	ln->info = info;
	ln->prox = l;
	ln->ant = NULL;
	if(l != NULL)
		l->ant = ln;
	return ln;
}

void lst_dupl_imprime(ListaDupl *l) {
	ListaDupl* lAux = l;
	
	while(lAux != NULL) {
		printf("Info = %d\n", lAux->info);
		lAux = lAux->prox;
	}
}

ListaDupl* lst_dupl_busca(ListaDupl *l, int info) {
	ListaDupl* lAux = l;
	while(lAux != NULL) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

ListaDupl* lst_dupl_remove(ListaDupl *l, int info) {
	ListaDupl* lAux = lst_dupl_busca(l, info);
	
	if(lAux == NULL)
		return l;
		
	if(lAux == l)
		lAux = lAux->prox;
	else
		lAux->ant->prox = lAux->prox;
		
	if(lAux != NULL)
		lAux->prox->ant = lAux->ant;
		
	free(lAux);
	
	return l;
}

void lst_dupl_libera(ListaDupl *l) {
	ListaDupl *lProx;
	
	while(lProx != NULL) {
		lProx = lProx->prox;
		free(l);
		l = lProx;
	}
}

ListaDupl* insere_fim_lista(ListaDupl *l, int x) {
	ListaDupl *ln = (ListaDupl*)malloc(sizeof(ListaDupl));
	ln->info = x;
	ln->prox = NULL;
	
	if(l == NULL) {
		ln->ant = NULL;
		return ln;
	}
	else {
		ListaDupl *lAux = l;
		
		while(lAux->prox != NULL)
			lAux = lAux->prox;
		lAux->prox = ln;
		ln->ant = lAux;
		
		return l;
	}
}
