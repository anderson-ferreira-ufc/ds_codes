//Trabalho 1 de Estrutura de Dados, quest�o 1 (lista encadeada)
typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lista_cria(); 
/* Testa se uma lista � vazia.*/
int lista_vazia(Lista *l); 
/* Insere um elemento no in�cio da lista.*/
Lista* lista_insere(Lista *l, int info); 
/* Busca um elemento em uma lista.*/
Lista* lista_busca(Lista *l, int info); 
/* Imprime uma lista.*/
void lista_imprime(Lista *l); 
/* Remove um elemento de uma lista.*/
Lista* lista_remove(Lista *l, int info); 
/* Libera o espa�o alocado por uma lista.*/
void lista_libera(Lista *l);
/*a) Retorna a quantidade de n�s da lista*/
int comprimento(Lista* l);
/*b) Retorna a quantidade de elementos menores que n*/
int menores(Lista *l, int n);
/*c) Retorna o somat�rio dos elementos da lista*/
int soma(Lista *l);
/*d) Retorna a quantidade de n�meros primos presentes na lista*/
int primos(Lista* l);
/*e) Concatena uma segunda lista no final da primeira lista*/
Lista* lst_conc(Lista* l1, Lista* l2);
/*f) Retira de l1 os elementos que possui em comum com l2, retornando apenas os elementos exclusivos de l1*/
Lista* lst_diferenca(Lista* l1, Lista* l2);

Lista* lista_remove_rec(Lista *l, int info);

int pertence_lista(int elemento, Lista* lista);

void lista_imprime_invertida_rec(Lista* l);
