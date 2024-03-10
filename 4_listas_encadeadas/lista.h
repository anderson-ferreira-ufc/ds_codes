typedef struct lista Lista;

/*Cria uma lista vazia*/
Lista* lst_cria();
/*Verifica se uma lista está vazia*/
int lst_vazia(Lista *l);
/*Insere um elemento no início da lista*/
Lista* lst_insere(Lista *l, int info);
/*Busca um elemento na lista*/
Lista* lst_busca(Lista *l, int info);
/*Imprime todos os elementos da lista*/
void lst_imprime(Lista *l);
/*Remove um elemento de uma lista*/
Lista* lst_remove(Lista *l, int info);
/*Libera o espaço ocupado pela lista*/
void lst_libera(Lista *l);
/*Insere um elemnto na lista de forma ordenada*/
Lista* lst_insere_ordenado(Lista *l, int info);
/*AP 1 2023.2 Segunda Chamada 1 Insere dois números no início e no fim da lista.*/
Lista* insere_inicio_fim_lista(Lista *l, int x, int y);
/*AP 1 2023.2 1 - a) Informa a quantidade de elementos menores que x*/
int qtd_menores_lista(Lista* l, int x);
/*AP 1 2023.2 1 - b)Insere um elemento no fim da lista*/
Lista* insere_fim_lista(Lista *l, int x);
