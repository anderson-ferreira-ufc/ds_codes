#include <stdio.h>
#include <stdlib.h>
#include "fila_lista.h"

struct lista {
	int info;
	Lista* prox;
};

struct fila {
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void) {
	Fila* f = (Fila*)malloc(sizeof(Fila));
	
	if(f == NULL) {
		printf("Memória insuficiente!\n");
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

int fila_remove(Fila* f) {
	Lista* l = f->ini;
	int a;
	
	if(fila_vazia(f)) {
		printf("Fila vazia!");
		exit(1);
	}
	a = l->info;
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
	Lista *l = f->ini;
	Lista *lAux;
	
	while(l != NULL) {
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}

Lista* lista_cria() {
    return NULL;
}


//a)
int qtd_maior(Fila* f, int n) {
	Lista *lAux = f->ini;
	int qtd = 0;
	
	while(lAux != NULL) {
		if(lAux->info > n)
			qtd++;
		lAux = lAux->prox;
	}
	return qtd;
}


void enfileira(Fila* f, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if (fila_vazia(f)) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileira(Fila* f) {
    if (fila_vazia(f)) {
        printf("Erro: fila vazia.\n");
        exit(EXIT_FAILURE);
    }

    int valor = f->ini->info;
    Lista* temp = f->ini;

    f->ini = f->ini->prox;

    if (f->ini == NULL) {
        f->fim = NULL;
    }

    free(temp);

    return valor;
}



//b)
Fila* inverte(Fila* f) {
    Fila* f_invertida = fila_cria();
    Lista* pilha_temp = lista_cria();

    // Transfere os elementos da fila para uma pilha temporária
    while (!fila_vazia(f)) {
        int elemento = desenfileira(f);
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->info = elemento;
        novo->prox = pilha_temp;
        pilha_temp = novo;
    }

    // Transfere os elementos da pilha para a fila invertida
    while (pilha_temp != NULL) {
        enfileira(f_invertida, pilha_temp->info);
        Lista* temp = pilha_temp;
        pilha_temp = pilha_temp->prox;
        free(temp);
    }

    return f_invertida;
}

//c)
int pares(Fila *f) {
	Lista *lAux = f->ini;
	int qtd_p = 0;
	
	while(lAux != NULL) {
		if((lAux->info % 2) == 0)
			qtd_p++;
		lAux = lAux->prox;
	}
	return qtd_p;
}
