#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.h"

struct lista {
	int info;
	Lista *prox;
};

struct pilha {
	Lista *prim;
};

Pilha* pilha_cria(void) {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha *p, int info) {
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

int pilha_vazia(Pilha *p) {
	return p->prim == NULL;
}

int pilha_pop(Pilha *p) {
	int a;
	Lista *l;
	
	if(pilha_vazia(p)) {
		printf("Pilha vazia!\n");
		exit(1);
	}
	
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

void pilha_imprime(Pilha *p) {
	Lista *lAux = p->prim;
	while(lAux != NULL) {
		printf("%d\n", lAux->info);
		lAux = lAux->prox;
	}
}

void pilha_libera(Pilha *p) {
	Lista* l = p->prim;
	Lista* lAux;
	
	while(l != NULL) {
		lAux = l->prox;
		free(p);
		l = lAux;
	}
	free(p);
}

//AP 1 2023.2 2 a)
void pilha_push_maior(Pilha *p, int info) {
	if(p->prim == NULL || info > p->prim->info) {
		Lista *l = (Lista*)malloc(sizeof(Lista));
		l->info = info;
		l->prox = p->prim;
		p->prim = l;
	}
}

//AP 1 2023.2 2 b)
int pilha_soma(Pilha *p) {
	if(p->prim == NULL) {
		printf("Pilha vazia!");
		exit(1);
	}
	else {
		Lista *lAux = p->prim;
		int soma = 0;
		
		while(lAux != NULL) {
			soma = soma + lAux->info;
			lAux = lAux->prox;
		}
		return soma;
	}
}

//AP 1 2023.2 Segunda Chamada 2 a)
Pilha* pilha_push_lista(Lista *l) {
	Lista *lAux = l;
	
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	
	while(lAux != NULL) {
		Lista *ln = (Lista*)malloc(sizeof(Lista));
		ln->info = lAux->info;
		ln->prox = p->prim;
		p->prim = ln;
		lAux = lAux->prox;
	}
	return p;
}

//AP 1 2023.2 Segunda Chamada 2 b)
Lista* lista_insere_pilha(Pilha *p) {
	Lista *lAux = p->prim;
	Lista *l = NULL;
	
	while(lAux != NULL) {
		Lista *ln = (Lista*)malloc(sizeof(Lista));
		ln->info = lAux->info;
		ln->prox = l;
		l = ln;
		lAux = lAux->prox;
	}
	return l;
}

Lista* lst_cria() {
	return NULL;
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

void lst_imprime(Lista *l) {
	Lista *lAux = l;
	
	while(lAux != NULL) {
		printf("%d ", lAux->info);
		lAux = lAux->prox;
	}
}
