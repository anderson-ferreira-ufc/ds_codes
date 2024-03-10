#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
	Lista* l = lst_cria();
	
	printf("Lista original:\n");
	l = lst_insere(l, 10);
	l = lst_insere(l, 7);
	l = lst_insere(l, 9);
	l = lst_insere(l, 4);
	l = lst_insere(l, 5);
	l = insere_inicio_fim_lista(l, 8, 12);
	
	lst_imprime(l);
	
	return 0;
}
