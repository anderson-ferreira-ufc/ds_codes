#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


int main(void) {
	Lista* l1 = lst_cria();
	
	l1 = lst_insere(l1, 4);
	l1 = lst_insere(l1, 2);
	l1 = lst_insere(l1, 7);
	l1 = lst_insere(l1, 1);
	l1 = lst_insere(l1, 0);
	l1 = insere_inicio_fim_lista(l1, -3, 15);
	lst_imprime(l1);
	
	return 0;
}
