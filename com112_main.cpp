//Estrutura de dados 2-Lista 4
//Gerar vetor de tamanho aleatorio com valores aleatorios e ordenacao atraves da escolha entre os metodos bubble, selection e insertion.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "com112_sort.h"
#include "com112_file.h"
//a variavel 'a' serve para identificar qual método de ordenação foi escolhido
int a;

void menu(int vetor[], clock_t tempo, int tamanho, int *comp)
{
	while(1)
	{
		int copiadovetor[tamanho];
		int mov;
		printf("\nEscolha uma das opções:\n(1)Bubble Sort\n(2)Selection Sort\n(3)Insertion Sort\n(4)Merge Sort\n(5)Quick Sort\n(6)Relatorio\n(7)Sair\n");
		scanf("%d", &a);
		if(a == 7 )return ;
		if(a == 1)
		{
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = bubble( copiadovetor, tamanho, comp, tempo, a);
		}

		if(a == 2)
		{
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = select(copiadovetor, tamanho, comp, tempo, a);
		}

		if(a == 3)
		{
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = insert(copiadovetor, tamanho, comp, tempo, a);
		}

		if(a == 4)
		{
			int tipo, trocas=0;
			*comp=0;
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = merge(copiadovetor, 0, tamanho, comp, &tipo, &trocas);
			escrever(copiadovetor, tamanho);
			escreverRelatorio(tempo, trocas, *comp, tamanho, a, tipo);
		}
		if(a == 5)
		{
			int trocas=0;
			*comp=0;
			int tipo;
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = quick(copiadovetor, tamanho, comp, tempo, a, &tipo, &trocas);
			escrever(copiadovetor, tamanho);
			escreverRelatorio(tempo, trocas, *comp, tamanho, a, tipo);
		}

		if(a == 6)
		{
			int tipo, trocas=0;
			//bubble sort
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = bubble( copiadovetor, tamanho, comp, tempo, a);
			//selection sort
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = select(copiadovetor, tamanho, comp, tempo, a);
			//insertion sort
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = insert(copiadovetor, tamanho, comp, tempo, a);
			//merge sort
			*comp=0;
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = merge(copiadovetor, 0, tamanho, comp, &tipo, &trocas);
			relatorio(tempo, trocas, *comp, tamanho, a, tipo);
			escreverRelatorio(tempo, trocas, *comp, tamanho, a, tipo);
			escrever(copiadovetor, tamanho);
			//quick sort
			trocas=0;
				*comp=0;
			copiarvetor(copiadovetor, vetor, tamanho);
			mov = quick(copiadovetor, tamanho, comp, tempo, a, &tipo, &trocas);
			relatorio(tempo, trocas, *comp, tamanho, a, tipo);
			escreverRelatorio(tempo, trocas, *comp, tamanho, a, tipo);
			escrever(copiadovetor, tamanho);
			


		}
	}

}

int main()
{
	printf("			Codigo para gerar valores aleatorios e ordenacao\n");
	clock_t tempo;
	tempo = clock();
	//Obs: gerar novos valores usa SRAND e por isso os valores sao dependentes da hora de execucao, nao podem ser utilizados novamente
	//Caso não escolha novos valores, sera usada a funcao RAND na qual os valores dependem da maquina e por isso podem ser utilizados em outras ordenacoes.
	printf("\nDeseja gerar novos valores de entrada ou usar os gerados anteriormente?\n(1)gerar novos\n(2)usar os mesmos\n");
	int mudar;
	scanf("%d", &mudar);
	system("cls");
	if(mudar == 1)srand(time(NULL));
	int tamanho;
	tamanho = tamanhoVetor();
	int vetor[tamanho];
	criavetor(vetor, tamanho);
	printf("\ntamanho : %d\n", tamanho);
	for(int i=0;i<tamanho;i++)printf("%d, ",vetor[i]);
	printf("\n");
	printf("--------MENU--------\n ");
	int comp = 0;
	menu(vetor, tempo, tamanho, &comp);
	return 0;
}