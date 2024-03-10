#include <stdio.h>
#include <stdlib.h>
#include "abb_numeros.h"
#define IND 10

int main(void) {
	ArvB* a1 = arvb_cria_vazia();
	
	a1 = arvb_insere(a1, 17);
	a1 = arvb_insere(a1,13);
	a1 = arvb_insere(a1, 11);
	a1 = arvb_insere(a1, 43);
	a1 = arvb_insere(a1, 19);
	
	arvb_imprime(a1);
	printf("\nNos primos: %d", folhas_primos(a1));
	return 0;
}
