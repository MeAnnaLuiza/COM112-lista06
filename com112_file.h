#ifndef com112_file
#define com112_file
//definicao da funcao que gera o tamanho do vetor
int tamanhoVetor();
void copiarvetor(int vetor1[], int vetor2[], int tamanho);
//definicao da funcao que gera os valores aleatorios
void criavetor(int *vetor, int tamanho);
//definicao da funcao que escreve o relatorio no arquivo
void escreverRelatorio(clock_t tempo, int mov, int comp, int tamanho, int a, int tipo);
void escrever(int vetor[], int tamanho);
void relatorio(clock_t tempo, int mov, int comp, int tamanho, int a, int tipo);
#endif