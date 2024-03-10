#include <stdio.h>
#include <stdlib.h>
#include "fila_lista.h"

int main(void) {
	Fila* f1 = fila_cria();
	
	printf("Fila original:\n");
	fila_insere(f1, 12);
	fila_insere(f1, 1);
	fila_insere(f1, 9);
	fila_insere(f1, 10);
	fila_insere(f1, 3);
	fila_imprime(f1);
	
	
	printf("\nFila alterada:\n");
	
	fila_retira_inicio_insere_fim(f1);
	fila_imprime(f1);
	return 0;
}
