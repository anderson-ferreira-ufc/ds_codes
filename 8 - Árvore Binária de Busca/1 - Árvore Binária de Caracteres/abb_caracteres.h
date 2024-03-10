typedef struct arv Arv;

//Cria uma Árvore Binária de Busca vazia.
Arv* arv_cria_vazia(void);
//Cria um nó na Árvore Binária de Busca.
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);
//Verifica se a Árvore Binária de Busca está vazia.
int arv_vazia(Arv *a);
//Imprime os elementos da Árvore Binária de Busca.
void arv_imprime(Arv *a);
//Verifica o caractere fornecido existe na Árvore Binária de Busca
int arv_pertence(Arv *a, char c);
//Libera o espaço alocado por um Árvore Binária de Busca.
void arv_libera(Arv *a);
//Retorna a altura da árvore.
int arv_altura(Arv *a);
