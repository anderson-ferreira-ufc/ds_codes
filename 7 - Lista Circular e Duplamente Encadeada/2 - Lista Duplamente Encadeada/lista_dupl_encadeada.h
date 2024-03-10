typedef struct lista_dupl ListaDupl;

/*Cria uma nova lista duplamente encadeada.*/
ListaDupl* lst_dupl_cria();
/*Verifica se uma lista duplamente encadeada está vazia.*/
int lst_dupl_vazia(ListaDupl *l);
/*Insere um novo elemento na lista duplamente encadeada.*/
ListaDupl* lst_dupl_insere(ListaDupl *l, int info);
/*Imprime a lista duplamente encadeada.*/
void lst_dupl_imprime(ListaDupl *l);
/*Procura um determinado elemento na lista duplamente encadeada.*/
ListaDupl* lst_dupl_busca(ListaDupl *l, int info);
/*Remove um elemento da lista duplamente encadeada.*/
ListaDupl* lst_dupl_remove(ListaDupl *l, int info);
/*Libera o espaço alocado por uma lista duplamente encadeada.*/
void lst_dupl_libera(ListaDupl *l);
/*Insere um novo elemento no fim da lista duplamente encadeada.*/
ListaDupl* insere_fim_lista(ListaDupl *l, int x);
