#include <stdio.h>
#include <stdlib.h>
#include "lista_dupl_encadeada.h"

int main(void) {
	ListaDupl* l = lst_dupl_cria();
	
	l = lst_dupl_insere(l, 7);
	l = lst_dupl_insere(l, -23);
	l = lst_dupl_insere(l, 2);
	l = lst_dupl_insere(l, 0);
	l = lst_dupl_insere(l, -11);
	l = insere_fim_lista(l, 12);
	
	lst_dupl_imprime(l);
	
	return 0;
}
