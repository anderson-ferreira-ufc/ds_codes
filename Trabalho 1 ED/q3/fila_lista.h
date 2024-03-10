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
/*a) Retorna a quantidade de elementos da fila maiores que n*/
int qtd_maior(Fila* f, int n);

void enfileira(Fila* f, int valor);

int desenfileira(Fila* f);

Lista* lista_cria();

/*b) Inverte a ordem da fila fornecida*/
Fila* inverte(Fila *f);
/*c) Retorna a quantidade de números pares da fila*/
int pares(Fila *f);
