#include <stdio.h>
#include <stdlib.h>
#include "fila_lista.h"

struct lista {
	int info;
	Lista *prox;
};

struct fila {
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria() {
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int fila_vazia(Fila *f) {
	return f->ini == NULL;
}

void fila_insere(Fila *f, int info) {
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	f->fim = l;
}

int fila_remove(Fila *f) {
	Lista *l;
	int a;
	
	if(fila_vazia(f)) {
		printf("Fila vazia!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	
	if(fila_vazia(f))
		f->fim = NULL;
	
	return a;
}

void fila_imprime(Fila *f) {
	Lista *lAux = f->ini;
	
	while(lAux != NULL) {
		printf("%d\n", lAux->info);
		lAux = lAux->prox;
	}
}

void fila_libera(Fila *f) {
	Lista* l = f->ini;
	Lista* lAux;
	
	while(l != NULL) {
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}
//AP 1 2023.2 3
int fila_retira_impar(Fila *f) {
	if(f->ini->info % 2 != 0) {
		Lista *l;
		int a;
		
		a = f->ini->info;
		l = f->ini;
		f->ini = f->ini->prox;
		free(l);
		
		if(fila_vazia(f))
			f->fim = NULL;
		return a;
	}
}

///*AP 1 2023.2 Segunda Chamada 2
void fila_retira_inicio_insere_fim(Fila *f) {
	Lista *l;
	int a;
	
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	
	if(f->ini == NULL)
		f->fim = NULL;
	
	Lista *lfim = (Lista*)malloc(sizeof(Lista));
	
	lfim->info = a;
	lfim->prox = NULL;
	
	if(!(f->ini == NULL))
		f->fim->prox = lfim;
	else
		f->ini = l;
	f->fim = l;
}
