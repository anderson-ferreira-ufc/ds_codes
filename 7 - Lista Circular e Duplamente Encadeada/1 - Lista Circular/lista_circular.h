typedef struct lista_circ ListaCirc;

/*Cria uma lista circular vazia.*/
ListaCirc* lst_circ_cria();
/*Verifica se uma lista circular está vazia.*/
int lst_circ_vazia(ListaCirc *l);
/*Insere um novo elemento na lista circular.*/
ListaCirc* lst_circ_insere(ListaCirc *l, int info);
/*Busca um determinado valor na lista circular.*/
ListaCirc* lst_circ_busca(ListaCirc *l, int info);
/*Imprime uma lista circular.*/
void lst_circ_imprime(ListaCirc *l);
/*Remove um determinado elemento da lista circular.*/
ListaCirc* lst_circ_remove(ListaCirc *l, int info);
/*Libera o espaço alocado por uma lista circular.*/
void lst_circ_libera(ListaCirc *l);
