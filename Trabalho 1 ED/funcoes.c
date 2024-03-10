#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

struct lista {
int info;
Lista *prox;
};

struct pilha{
 Lista *prim;
};

struct fila{
 Lista *ini;
 Lista *fim;
};

Lista* lst_cria(){
 return NULL;
}

int lst_vazia(Lista *l){
 return (l==NULL);
}

Lista* lst_insere(Lista *l, int info){
 Lista* ln = (Lista*)malloc(sizeof(Lista));
 ln->info = info;
 ln->prox = l;
 return ln;
}

Lista* lst_busca(Lista *l, int info){
 Lista* lAux = l;
 while(lAux!=NULL){
 if(lAux->info == info)
 return lAux;
 lAux = lAux->prox;
 }
 return NULL;
}

void lst_imprime(Lista *l){
 Lista* lAux = l;
 while(lAux!=NULL){
 printf("Info = %d\n",lAux->info);
 lAux = lAux->prox;
 }
}

Lista* lst_remove(Lista *l, int info){
if(l!=NULL){
 Lista* lAux = l->prox;
 if(l->info==info){
 free(l);
 return lAux;
 }
 else{
 Lista* lAnt = l;
 while(lAux!=NULL ){
 if(lAux->info == info){
 lAnt->prox = lAux->prox;
 free(lAux);
 break;
 }else{
 lAnt = lAux;
 lAux = lAux->prox;
 }
 } 
 } 
}
return l;
}

void lst_libera(Lista *l){
 Lista* lProx;
 while(l!=NULL){
 lProx = l->prox;
 free(l);
 l = lProx;
 }
}

Pilha* pilha_cria(void){
 Pilha *p = (Pilha*)malloc(sizeof(Pilha));
 if(p==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 p->prim = NULL;
 return p;
}

void pilha_push(Pilha *p, int info){
 Lista *l = (Lista*)malloc(sizeof(Lista));
 if(l==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 l->info = info;
 l->prox = p->prim;
 p->prim = l;
}

int pilha_vazia(Pilha *p){
 return p->prim==NULL;
}

int pilha_pop(Pilha *p){
 int a;
 Lista *l;
 if(pilha_vazia(p)){
 printf("Pilha Vazia!!!\n");
 exit(1); 
 }
 l = p->prim;
 a = l->info;
 p->prim = l->prox;
 free(l);
 return a;
}

void pilha_imprime(Pilha *p){
 Lista *lAux = p->prim;
 while(lAux!=NULL){
 printf("%f\n",lAux->info);
 lAux = lAux->prox;
 }
}

void pilha_libera(Pilha *p){
 Lista* l = p->prim;
 Lista* lAux;
 while(l!=NULL){
 lAux = l->prox;
 free(l);
 l = lAux;
 }
 free(p);
}

Fila* fila_cria(void){
 Fila *f = (Fila*)malloc(sizeof(Fila));
 if(f==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 f->ini = NULL;
 f->fim = NULL;
 return f;
}

void fila_insere(Fila *f, int info){
 Lista *l = (Lista*)malloc(sizeof(Lista));
 if(l==NULL){
 printf("Memoria insuficiente!!!\n");
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

int fila_vazia(Fila *f){
 return f->ini==NULL;
}

int fila_remove(Fila *f){
 Lista *l; int a;
 if(fila_vazia(f)){
 printf("Fila Vazia!!!\n");
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

void fila_imprime(Fila *f){
 Lista *lAux = f->ini;
 while(lAux!=NULL){
 printf("%d\n",lAux->info);
 lAux = lAux->prox;
 }
}

void fila_libera(Fila *f){
 Lista* l = f->ini;
 Lista* lAux;
 while(l!=NULL){
 lAux = l->prox;
 free(l);
 l = lAux;
 }
 free(f);
}

Lista* insere_inicio_fim_lista(Lista* inicio, int x, int y) {
    // Cria um novo nó para o valor x
    Lista* novoX = (Lista*)malloc(sizeof(Lista));
    novoX->info = x;
    novoX->prox = inicio; // O novo nó aponta para o antigo início
    inicio = novoX; // Atualiza o início da lista

    // Cria um novo nó para o valor y
    Lista* novoY = (Lista*)malloc(sizeof(Lista));
    novoY->info = y;
    novoY->prox = NULL; // O novo nó no fim aponta para NULL

    if (inicio == NULL) {
        // Se a lista estava vazia, o novo nó com valor y será o início
        inicio = novoY;
    } else {
        // Percorre a lista até o último nó
        Lista* atual = inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Atualiza o próximo do último nó para apontar para o novo nó com valor y
        atual->prox = novoY;
    }

    return inicio;
}

void fila_retira_inicio_insere_fim(Fila* f) {
    if (f->ini == NULL) {
        // A fila está vazia, não há elementos para mover
        return;
    }

    if (f->ini == f->fim) {
        // Se há apenas um elemento na fila, não é necessário fazer nada
        return;
    }

    // Remove o primeiro elemento da fila
    Lista* retirado = f->ini;
    f->ini = retirado->prox;

    // Insere o elemento retirado no fim da fila
    retirado->prox = NULL;
    f->fim->prox = retirado;
    f->fim = retirado;
}

Lista* insere_pilha(Pilha* pilha) {
    Lista* lista = NULL;

    Lista* atual = pilha->prim;

    while (atual != NULL) {
        // Cria um novo nó na lista
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->info = atual->info;
        novo->prox = lista; // O novo nó aponta para o início da lista
        lista = novo; // Atualiza o início da lista

        atual = atual->prox; // Move para o próximo elemento da pilha
    }

    return lista;
}

Pilha* pilha_push_lista(Lista* lista) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->prim = NULL; // Inicializa a pilha como vazia

    Lista* atual = lista;

    while (atual != NULL) {
        // Cria um novo nó na pilha
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->info = atual->info;
        novo->prox = pilha->prim; // O novo nó aponta para o topo da pilha
        pilha->prim = novo; // Atualiza o topo da pilha

        atual = atual->prox; // Move para o próximo elemento da lista
    }

    return pilha;
}
