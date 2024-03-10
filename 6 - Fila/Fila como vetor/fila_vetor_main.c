#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

int main(void) {
	Fila* f1;
	f1 = fila_cria();
	fila_insere(f1, -6);
	fila_insere(f1, 9);
	fila_insere(f1, 0);
	fila_remove(f1);
	fila_imprime(f1);
	
	return 0;
}
