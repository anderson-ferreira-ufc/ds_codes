typedef struct lista Lista;
typedef struct fila Fila;

/*Função que cria uma Fila.*/
Fila* fila_cria(void);
/*Testa se uma Fila é vazia.*/
int fila_vazia(Fila *f);
/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);
/*Função que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);
/*Função que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);
/*Libera o espaço alocado para uma Fila.*/
void fila_libera(Fila *f);
/*AP 1 2023.2 3 Retira o elemento no início da fila somente se for ímpar.*/
int fila_retira_impar(Fila *f);
/*AP 1 2023.2 Segunda Chamada 3 Insere dois números no início e no fim da lista.*/
void fila_retira_inicio_insere_fim(Fila *f);
