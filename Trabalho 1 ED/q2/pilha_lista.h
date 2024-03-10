//Trabalho 1 de Estrutura de Dados, questão 2 (pilhas)
typedef struct lista Lista;
typedef struct pilha Pilha;

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void);
/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p);
/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);
/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);
/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p);
/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p);
/*a) Retorna o valor no topo da fila.*/
int topo(Pilha *p);
/*b) Retorna a quantidade de números ímpares presentes na pilha.*/
int impares(Pilha *p);
/*c) Cria uma nova pilha de elementos pares contidos na pilha 1.*/
Pilha* empilha_pares(Pilha *p1, Pilha *p2);
