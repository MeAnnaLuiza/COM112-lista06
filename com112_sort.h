#ifndef com112_sort
#define com112_sort
//definicao das funcoes de ordenacao
int  bubble(int vetor[], int tamanho, int *comp, clock_t tempo, int a);
int select(int vetor[], int tamanho, int *comp, clock_t tempo, int a);
int insert(int vetor[], int tamanho, int *comp, clock_t tempo, int a);
int merge(int vetor[], int l, int r, int *comp, int *tipo, int *trocas);
int quick(int vetor[], int tamanho, int *comp, clock_t tempo, int a, int *tipo, int *trocas);
//definicao da funcao swap em c
void inverte(int *a, int *b);
#endif