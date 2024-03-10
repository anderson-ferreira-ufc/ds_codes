#include <stdio.h>
#include <stdlib.h>
#include "pilha_vetor.h"

int main(void) {
	Pilha* p = pilha_cria();
	pilha_push(p, 6);
	pilha_push(p, 8);
	pilha_push(p, 2);
	pilha_imprime(p);
	printf("Pilha vazia: %d", pilha_vazia(p));
	
	return 0;
}
