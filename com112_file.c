   #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "com112_sort.h"
#include "com112_file.h"

void copiarvetor(int copiadovetor[], int vetor[], int tamanho){
	int i;
	for(i=0;i<tamanho;i++)copiadovetor[i]=vetor[i];
}

//funcao para gerar o tamanho do vetor aleatoriamente
void relatorio(clock_t tempo, int mov, int comp, int tamanho, int a, int tipo)
{
	tempo = clock() - tempo;
	if(tipo == 1)printf("\nMetodo Bubble Sort\n");
	if(tipo == 2)printf("\nMetodo Selection Sort\n");
	if(tipo == 3)printf("\nMetodo Insertion Sort\n");
	if(tipo == 4)printf("\nMetodo Merge Sort\n");
	if(tipo == 5)printf("\nMetodo Quick Sort\n");
	printf("\nNumero de elementos ordenados: %d", tamanho);
	printf("\nTempo de execucao: %.0lf", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
	printf("\nNumero de movimentacoes: %d", mov);
	printf("\nNumero de comparacoes: %d\n", comp);
	
}
void escrever(int vetor[], int tamanho)
{
	int i;
	FILE *leitura;
	leitura = fopen(" com112_saida.txt", "a+");
	fprintf(leitura, "\n%d\n", tamanho);
	for(i = 0; i < tamanho; i++)
		fprintf(leitura, "%d, ", vetor[i]);
}
int tamanhoVetor()
{
	FILE *criaArquivo;
	criaArquivo = fopen(" com112_entrada.txt", "a++");
	if(criaArquivo == NULL)
	{
		printf("Erro na criação do arquivo entrada.");
		return 0;
	}
	int tamanho = rand() % 100;
	fprintf(criaArquivo, "\n\n%d\n", tamanho);
	return tamanho;
}

//gerador de valores aleatorios para o vetor e armazenando no arquivo de entrada.
void criavetor(int *vetor, int tamanho)
{
	int i;
	for(i = 0; i < tamanho; i++)
		vetor[i] = (rand()%100);
	FILE *leitura;
	leitura = fopen(" com112_entrada.txt", "a++");
	for(i = 0; i < tamanho; i++)
		fprintf(leitura, "%d ", vetor[i]);
}

//funcao para escrever os dados do relatorio no arquivo de saida
void escreverRelatorio(clock_t tempo, int mov, int comp, int tamanho, int a, int tipo)
{
	FILE *criaArquivo;
	criaArquivo = fopen(" com112_relatorio.txt", "a+");
	if(criaArquivo == NULL)
		printf("Erro na criação do arquivo entrada.");
	fprintf(criaArquivo, "Numero de elementos ordenados: %d", tamanho);
	if(tipo == 1)fprintf(criaArquivo, "\nMetodo Bubble Sort\n");
	if(tipo == 2)fprintf(criaArquivo, "\nMetodo Selection Sort\n");
	if(tipo == 3)fprintf(criaArquivo, "\nMetodo Insertion Sort\n");
	if(tipo == 4)fprintf(criaArquivo, "\nMetodo Merge Sort\n");
	if(tipo == 5)fprintf(criaArquivo, "\nMetodo Quick Sort Sort\n");
	fprintf(criaArquivo, "		Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
	fprintf(criaArquivo, "		Numero de comparacoes: %d\n", comp);
	fprintf(criaArquivo, "		Numero de movimentacoes: %d\n", mov);
}