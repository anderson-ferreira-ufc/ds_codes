#include <stdio.h>
#include <stdlib.h>
#include "abb_numeros.h"

int main(void) {
	ArvB* a1 = arvb_cria_vazia();
	
	a1 = arvb_insere(a1, 6);
	a1 = arvb_insere(a1, 4);
	a1 = arvb_insere(a1, 9);
	a1 = arvb_insere(a1, 8);
	a1 = arvb_insere(a1, 1);
	
	arvb_imprime(a1);
	printf("\nNós pares: %d", qtd_nos_arv(a1));
	return 0;
}
