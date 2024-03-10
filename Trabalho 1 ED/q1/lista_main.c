//Trabalho 1 de Estrutura de Dados, questão 1 (lista encadeada)
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {	
	Lista* l1 = lista_cria();
	
	l1 = lista_insere(l1,6);
	l1 = lista_insere(l1,13);
	l1 = lista_insere(l1,45);
	l1 = lista_insere(l1,28);
	l1 = lista_insere(l1,41);
	l1 = lista_remove(l1,25);
	l1 = lista_remove_rec(l1,41);
	
	lista_imprime(l1);
	lista_imprime_invertida_rec(l1);
	
	printf("Num. nos c/ info < que 30: %d\n", menores(l1,30));
	printf("O comprimento da lista eh %d\n", comprimento(l1));
	printf("Soma dos valores dos nos %d\n" , soma(l1)); 
	printf("Num. nos com val. primos eh %d\n", primos(l1));
	
	Lista* l2 = lista_cria();
	l2 = lista_insere(l2,28);
	l2 = lista_insere(l2,45); 
	l2 = lista_insere(l2,130); 
	
	Lista* l3=lst_conc(l1,l2); 
	lista_imprime(l3);
	l1=lst_diferenca(l1,l2);
	lista_imprime(l1); 
	
	lista_libera(l1);
	lista_libera(l2); 
	lista_libera(l3);
	
	system("PAUSE");
	return 0;
}
