#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#define MAX 5

struct aluno{
	char nome[81];
	float ira;
};

void inicializa(int n, Aluno **alunos) {
	int i;
    for (i = 0; i < n; i++) {
        alunos[i] = NULL;
    }
}

void imprime(int n, Aluno **alunos, int i) {
    if (alunos[i] != NULL) {
        printf("Nome: %s\n", alunos[i]->nome);
        printf("IRA: %.2f\n", alunos[i]->ira);
    } else {
        printf("Nenhum aluno registrado nesta posição.\n");
    }
}

int buscaBinariaNome(int n, Aluno **alunos, char *nome) {
	int ini = 0, fim = n - 1, meio, r;
	
	while(fim - ini >= 0) {
		meio = (ini + fim)/2;
		r = strcmp(nome, alunos[meio]->nome);
		
		if(r == 0)
			return meio;
		else if(r > 0)
			ini = meio + 1;
		else if(r < 0)
			fim = meio -1;
	}
	return -1;
}

void imprime_todos(int n, Aluno **alunos) {
    int i;
    for (i = 0; i < n; i++) {
        if (alunos[i] != NULL) {
            printf("Posição %d:\n", i);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("IRA: %.2f\n", alunos[i]->ira);
        } else {
            printf("Posição %d: Nenhum aluno registrado.\n", i);
        }
    }
}

void atualiza(int n, Aluno **alunos, int i) {
    if (alunos[i] == NULL) {
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
        if (alunos[i] == NULL) {
            fprintf(stderr, "Erro: Falha na alocação de memória.\n");
            exit(EXIT_FAILURE);
        }

        printf("Informe o nome do aluno: ");
        scanf("%80s", alunos[i]->nome);

        printf("Informe a IRA do aluno: ");
        scanf("%f", &alunos[i]->ira);
    }
}

void exclui(int n, Aluno **alunos, int i) {
    if (alunos[i] != NULL) {
        free(alunos[i]);
        alunos[i] = NULL;
    }
}
