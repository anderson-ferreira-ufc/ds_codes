#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
	ListaCirc *l = lst_circ_cria();
	
	l = lst_circ_insere(l, 12);
	l = lst_circ_insere(l, 1);
	l = lst_circ_insere(l, 8);
	l = lst_circ_insere(l, 14);
	l = lst_circ_insere(l, 26);
	l = lst_circ_insere(l, 18);
	lst_circ_libera(l);
	
	lst_circ_imprime(l);
	
	return 0;
}
