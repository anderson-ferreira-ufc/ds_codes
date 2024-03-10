typedef struct pilha Pilha;
typedef struct lista Lista;

/*Cria uma pilha dinâmica vazia*/
Pilha* pilha_cria(void);
/*Insere um novo elemento no topo da pilha*/
void pilha_push(Pilha *p, int info);
/*Verifica se uma pilha está vazia*/
int pilha_vazia(Pilha *p);
/*Remove o elemento do topo da pilha*/
int pilha_pop(Pilha *p);
/*Imprime os elementos da pilha a partir do topo*/
void pilha_imprime(Pilha *p);
/*Libera o espaço alocado pela pilha*/
void pilha_libera(Pilha *p);
/*AP 1 2023.2 2 a) Insere um novo elemento no topo da pilha somente se for maior que o já existente no topo.*/
void pilha_push_maior(Pilha *p, int info);
//AP 1 2023.2 2 b) Efetua o somatório dos elementos da pilha.
int pilha_soma(Pilha *p);
/*AP 1 2023.2 Segunda Chamada 2 a) Gera uma pilha retirando elementos de uma lista, obedecendo a ordem. */
Pilha* pilha_push_lista(Lista *l);
/*AP 1 2023.2 Segunda Chamada 2 b) Gera uma lista com os elementos de uma pilha fornecida, na ordem. */
Lista* lista_insere_pilha(Pilha *p);
/*Cria uma nova lista vazia.*/
Lista* lst_cria(void);
/*Insere um novo elemento na lista encadeada.*/
Lista* lst_insere(Lista *l, int info);
/*Imprime todos os elementos da lista na ordem.*/
void lst_imprime(Lista *l);
