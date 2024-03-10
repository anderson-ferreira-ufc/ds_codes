//Trabalho 1 de Estrutura de Dados, questão 2 (pilhas)
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

Pilha* pilha_cria() {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p == NULL) {
		printf("Memória insuficiente!");
		exit(1);
	}
	
	p->prim = NULL;
	return p;
}

int pilha_vazia(Pilha *p) {
	return p->prim==NULL;
}

void pilha_push(Pilha *p, int info) {
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l == NULL) {
		printf("Memoria insuficiente\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	
	if(pilha_vazia(p)) {
		printf("Pilha Vazia!!!\n");
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
	Lista *l = p->prim;
	Lista *lAux;
	
	while(l != NULL) {
		lAux = l->prox;
		free(l);
		l = lAux;
	}
}


//a)
int topo(Pilha *p) {
	Lista *l = p->prim;
	int t;
	t = l->info;
	return t;
}

//b)
int impares(Pilha *p) {
	Lista *lAux = p->prim;
	int qtd_imp = 0;
	
	while(lAux != NULL) {
		if((lAux->info % 2) != 0)
			qtd_imp++;
		lAux = lAux->prox;
	}
	return qtd_imp;
}

//c)
Pilha* empilha_pares(Pilha* p1, Pilha* p2) {
    Lista* aux = p1->prim;

    // Percorre a pilha p1
    while (aux != NULL) {
        // Verifica se o elemento é par
        if (aux->info % 2 == 0) {
            // Cria um novo nó para o elemento par
            Lista* novo = (Lista*)malloc(sizeof(Lista));
            novo->info = aux->info;
            novo->prox = NULL;

            // Insere o novo nó na pilha p2 em ordem crescente
            if (p2->prim == NULL || novo->info <= p2->prim->info) {
                novo->prox = p2->prim;
                p2->prim = novo;
            } else {
                Lista* atual = p2->prim;
                while (atual->prox != NULL && atual->prox->info < novo->info) {
                    atual = atual->prox;
                }
                novo->prox = atual->prox;
                atual->prox = novo;
            }
        }

        aux = aux->prox;
    }

    // Retorna o ponteiro para a pilha p2
    return p2;
}
