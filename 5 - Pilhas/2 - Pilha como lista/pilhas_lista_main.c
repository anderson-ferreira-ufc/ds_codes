#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.h"



int main() {
	Pilha *p1 = pilha_cria();
	Lista *l = lst_cria();
	
	pilha_push(p1, 8);
	pilha_push(p1, 25);
	pilha_push(p1, 2);
	pilha_push(p1, 4);
	pilha_push(p1, 13);
	
	printf("Pilha:\n");
	pilha_imprime(p1);
	
	printf("\n\nLista gerada:\n");
	l = lista_insere_pilha(p1);
	
	lst_imprime(l);
	
		
	return 0;
}
