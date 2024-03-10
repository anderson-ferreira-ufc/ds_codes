typedef struct pilha Pilha;

/*Cria uma pilha vazia*/
Pilha* pilha_cria(void);
/*Insere um novo elemento no topo da pilha*/
void pilha_push(Pilha *p, int info);
/*Imprime a pilha come�ando pelo elemento do topo*/
void pilha_imprime(Pilha *p);
/*Libera o espa�o alocado pela pilha*/
void pilha_libera(Pilha *p);
/*Verifica se uma pilha est� vazia*/
int pilha_vazia(Pilha *p);
/*Remove um elemento do topo da pilha*/
int pilha_pop(Pilha *p);
