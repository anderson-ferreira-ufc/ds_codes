#include <stdio.h>
#include <stdlib.h>
#include "abb_caracteres.h"

int main() {
	//arv_cria_vazia();
	Arv* a1 = arv_cria_no('+', arv_cria_no('2', NULL, NULL), arv_cria_no('3', NULL, NULL));
	arv_imprime(a1);
	arv_libera(a1);
	
	//printf("\nArvore vazia: %d",);
	//printf("\nNum pertence a arvore: %d", arv_pertence(a1, '3'));
	//printf("\nAltura = %d", arv_altura(a1));
	return 0;
}
