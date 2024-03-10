#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"
#define N 3

typedef struct fila {
	int n;
	int ini;
	int v[N];
}Fila;

Fila* fila_cria(void) {
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f == NULL) {
		printf("Memória insuficiente!");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere(Fila *f, int info) {
	int fim;
	
	if(f->n == N) {
		printf("A capacidade da fila estourou!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim] = info;
	f->n++;
}

int fila_vazia(Fila *f) {
	return f->n == 0;
}

int fila_remove(Fila *f) {
	int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!\n");
		exit(1);
	}
	
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;

	return a;
}

void fila_imprime(Fila *f){
	int i; int k;
	
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}

void fila_libera(Fila *f){
	free(f);
}
