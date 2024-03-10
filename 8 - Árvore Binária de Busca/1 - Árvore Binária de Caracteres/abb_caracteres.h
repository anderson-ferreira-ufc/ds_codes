typedef struct arv Arv;

//Cria uma �rvore Bin�ria de Busca vazia.
Arv* arv_cria_vazia(void);
//Cria um n� na �rvore Bin�ria de Busca.
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);
//Verifica se a �rvore Bin�ria de Busca est� vazia.
int arv_vazia(Arv *a);
//Imprime os elementos da �rvore Bin�ria de Busca.
void arv_imprime(Arv *a);
//Verifica o caractere fornecido existe na �rvore Bin�ria de Busca
int arv_pertence(Arv *a, char c);
//Libera o espa�o alocado por um �rvore Bin�ria de Busca.
void arv_libera(Arv *a);
//Retorna a altura da �rvore.
int arv_altura(Arv *a);
