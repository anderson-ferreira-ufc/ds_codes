typedef struct lista Lista;
typedef struct pilha Pilha;
typedef struct fila Fila;

/* Cria uma lista vazia.*/
Lista* lst_cria(); 
/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l); 
/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info); 
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info); 
/* Imprime uma lista.*/
void lst_imprime(Lista *l); 
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info); 
/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void);
/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p);
/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);
/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);
/*Fun��o que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha *p);
/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha *p);

/*Fun��o que cria uma Fila.*/
Fila* fila_cria(void);
/*Testa se uma Fila � vazia.*/
int fila_vazia(Fila *f);
/*Fun��o que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);
/*Fun��o que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);
/*Fun��o que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);
/*Libera o espa�o alocado para uma Fila.*/
void fila_libera(Fila *f);

Pilha* pilha_push_lista(Lista* lista);

Lista* insere_inicio_fim_lista(Lista* inicio, int x, int y);

void fila_retira_inicio_insere_fim(Fila* f);

Lista* insere_pilha(Pilha* pilha);

Pilha* pilha_push_lista(Lista* lista);
