//Trabalho 1 de Estrutura de Dados, questão 1 (lista encadeada)
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

Lista* lista_cria(){
	return NULL;
}

int lista_vazia(Lista *l){
	return (l==NULL);
}

Lista* lista_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

Lista* lista_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	
	return NULL;
}

void lista_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("%d ",lAux->info);
		lAux = lAux->prox;
	}
}

Lista* lista_remove(Lista *l, int info) {
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

void lista_libera(Lista *l) {
	Lista* lProx;
	while(l != NULL) {
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

void lista_imprime_invertida_rec(Lista* l){
	if(lista_vazia(l))
		return;
	else{
		lista_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
	}
}

Lista* lista_remove_rec(Lista *l, int info){
	if(!lista_vazia(l)) {
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
		}
		else {
			l->prox = lista_remove_rec(l->prox,info);
		}
	}
	return l;
}


//a)
int comprimento(Lista* l) {
	Lista* lAux = l;
	int cont = 0;
	
	while(lAux != NULL) {
		cont++;
		lAux = lAux->prox;
	}
	return cont;
}

//b)
int menores(Lista *l, int n)  {
	Lista* lAux = l;
	int qtd_menores = 0;
	
	while(lAux != NULL) {
		if(lAux->info < n)
			qtd_menores++;
		lAux = lAux->prox;
	}
	
	return qtd_menores;
}

//c)
int soma(Lista* l) {
	Lista* lAux = l;
	int somatorio = 0;
	
	while(lAux != NULL) {
		somatorio = somatorio + lAux->info;
		lAux = lAux->prox;
	}
	
	return somatorio;
}

//d)
int primos(Lista* l) {
	Lista* lAux = l;
	int qtd_primos = 0;
	
	while(lAux != NULL) {
		if(lAux->info < 2) {
			lAux = lAux->prox;
		}
		else {
			int verifica = 0, i;
			
			for(i = 2; i < lAux->info; i++) {
				if((lAux->info % i) == 0) {
					verifica = 1;
					break;
				}
			}
			
			if(verifica == 0) {
				qtd_primos++;
			}
			
			lAux = lAux->prox;
		}
	}
	return qtd_primos;
}

//e)
Lista* lst_conc(Lista* l1, Lista* l2) {
	if(l1 == NULL)
		return l2;
	
	Lista *lAux1 = l1;
	
	while(lAux1->prox!= NULL) {
		lAux1 = lAux1->prox;
	}
	
	lAux1->prox = l2;
	
	return l1;
}

//f)
/*Lista* lst_diferenca(Lista* l1, Lista* l2) {
	Lista *lAux1 = l1;
	Lista *lAux2 = l2;
	
	if(l1 == NULL)
		return NULL;
	
	while(lAux1->prox != NULL) {
		while(lAux2->prox != NULL) {
			if(lAux2->info == lAux1->info) {
				lista_remove(l1, lAux1->info);
				break;
			}
			lAux2 = lAux2->prox;
		}
		lAux1 = lAux1->prox;
	}
	return l1;
}*/


int pertence_lista(int elemento, Lista* lista) {
    while (lista != NULL) {
        if (lista->info == elemento) {
            return 1; // O elemento pertence à lista
        }
        lista = lista->prox;
    }
    return 0; // O elemento não pertence à lista
}

Lista* lst_diferenca(Lista* l1, Lista* l2) {
    Lista* resultado = NULL;
    
    while (l1 != NULL) {
        // Verificar se o elemento atual de l1 está presente em l2
        if (!pertence_lista(l1->info, l2)) {
            // Adicionar o elemento ao resultado
            Lista* novo_elemento = (Lista*)malloc(sizeof(Lista));
            novo_elemento->info = l1->info;
            novo_elemento->prox = resultado;
            resultado = novo_elemento;
        }
        
        // Avançar para o próximo elemento de l1
        l1 = l1->prox;
    }

    // Inverter a ordem dos elementos na lista resultado
    Lista* aux = NULL;
    while (resultado != NULL) {
        Lista* proximo = resultado->prox;
        resultado->prox = aux;
        aux = resultado;
        resultado = proximo;
    }

    return aux;
}
