typedef struct aluno Aluno;

//Inicializa um vetor vazio.
void inicializa(int n, Aluno **alunos);
//Imprime o campo procurado.
void imprime(int n, Aluno **alunos, int i);
//Retorna o índice do campo nome.
int buscaNome(int n, Aluno **alunos, char *nome);
//Imprime todos os nomes dos alunos cadastrados.
void imprime_todos(int n, Aluno **alunos);
//Atualiza ou insere um novo aluno, se houver espaço disponível.
void atualiza(int n, Aluno **alunos, int i);
//Exclui o aluno do array.
void exclui(int n, Aluno **alunos, int i);
