#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"
#define MAX 5

int main(void) {	
	Aluno* alunos[MAX]; int i; int a;
	
	incializa(MAX,alunos);
	
	for(i=0;i<MAX;i++)
		atualiza(MAX,alunos,i);
	a = buscaNome(MAX,alunos,"JOSE");
	
	imprime(MAX,alunos,a);
	
	for(i=0;i<MAX;i++)
		exclui(MAX,alunos,i);
	return 0; 
}
