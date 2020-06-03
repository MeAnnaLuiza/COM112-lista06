#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "com112_sort.h"
#include "com112_file.h"
//implementacao do swap em c
void inverte(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//ordenacao com bubble sort retornando movimentacoes e incrementando as comparacoes.
int bubble(int vetor[], int tamanho,  int *comp, clock_t tempo, int a )
{

	int tipo = 1;
	int compara = 0;
	int mov = 0;
	int i, temp, j;
	for(i = tamanho; i >= 0; i--)
		for(j = tamanho; j > tamanho - i; j--)
		{
			compara++;
			if(vetor[j] < vetor[j - 1])
			{
				temp = vetor[j];
				vetor[j] = vetor[j - 1];
				vetor[j - 1] = temp;
				mov++;
			}
		}
	*comp = compara;
	escrever(vetor, tamanho);
	escreverRelatorio(tempo, mov, *comp, tamanho, a, tipo);
	if(a == 6)relatorio(tempo, mov, *comp, tamanho, a, tipo);
	return mov;
}

//ordenacao com selection sort retornando movimentacoes e incrementando as comparacoes.
int  select(int vetor[], int tamanho, int *comp, clock_t tempo, int a)
{
	int tipo = 2;
	int compara = 0;
	int mov = 0;
	int i, j, min;
	for(i = 0; i < tamanho - 1; i++)
	{
		min = i;
		for(j = i + 1; j < tamanho; j++)
		{
			compara++;
			if(vetor[j] < vetor[min])
			{
				min = j;
			}
		}
		inverte(&vetor[min], &vetor[i]);
		mov++;
	}
	*comp = compara;
	escrever(vetor, tamanho);
	escreverRelatorio(tempo, mov, *comp, tamanho, a, tipo);
	if(a == 6)relatorio(tempo, mov, *comp, tamanho, a, tipo);
	return mov;


}
//ordenacao com insertion sort retornando movimentacoes e incrementando as comparacoes.
int insert(int vetor[], int tamanho, int *comp, clock_t tempo, int a)
{
	int tipo = 3;
	int compara = 0;
	int mov = 0;
	int i, j, k;
	
	for(i = 1; i < tamanho; i++)
	{
		k = vetor[i];
		j = i - 1;
		while(j >= 0 && vetor[j] > k)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
			compara++;
			mov++;
		}
		vetor[j + 1] = k;
		mov++;
	}
	*comp = compara;
	escrever(vetor, tamanho);
	
	escreverRelatorio(tempo, mov, *comp, tamanho, a, tipo);
	if(a == 6)relatorio(tempo, mov, *comp, tamanho, a, tipo);
	return mov;
}


//ordenacao com merge sort retornando movimentacoes e incrementando as comparacoes.
int movMerge=0;
int compMerge=0;
//PRECISO APRENDER A CONTAR AS COMPARACOES E MUDANÇAS
int merge(int v[], int l, int r, int *comp, int *tipo, int *trocas)
{
	int mov=0;
	*tipo = 4;
	if (l >= r)
		return 0 ;

	long long int mid = (l + r) / 2;

	merge (v, l, mid, comp, tipo, trocas);
	merge(v, mid + 1, r, comp, tipo, trocas);

	int qtdElementosL = mid - l + 1;
	int qtdElementosR = r - (mid + 1) + 1;

	int vetorL[qtdElementosL];
	int vetorR[qtdElementosR];

	for (int i = l; i <= mid; ++i)
	{
		vetorL[i - l] = v[i];
		movMerge++;
	
	}

	for (int i = mid + 1; i <= r; ++i){
		vetorR[i - (mid + 1)] = v[i];
		movMerge++;
	}
		

	// Ja ordenei as metades da esquerda e da direita
	// Preciso unir essas duas metades de forma ordenada
	int posL = 0, posR = 0;
	for (int i = l; i <= r; ++i)
	{
		int elementoAtual;
	
		if (posL >= qtdElementosL)
		{
			elementoAtual = vetorR[posR];
			posR++;
			movMerge++;
			compMerge++;
			
		}
		else if (posR >= qtdElementosR)
		{
			elementoAtual = vetorL[posL];
			posL++;
			movMerge++;
			compMerge+=2;
		
		}
		else if (vetorL[posL] <= vetorR[posR])
		{
			
			elementoAtual = vetorL[posL];
			posL++;
			movMerge++;
			compMerge+=3;
			
		}
		else
		{
			compMerge++;
			elementoAtual = vetorR[posR];
			posR++;
			movMerge+=3;
		}

		v[i] = elementoAtual;
	}
	*comp=compMerge;
	*trocas=movMerge;
	return mov;
}

int movQuick=0;
int compQuick=0;
int quick(int vetor[], int tamanho, int *comp, clock_t tempo, int a, int *tipo, int *trocas )
{

	int mov=0;
	*tipo = 5;
	int K = vetor[tamanho - 1];
	int enderecoMaior = 0;
	for (int i = 0; i < tamanho - 1; i++)
	{
		compQuick++;
		if (vetor[i] < K)
		{
			
			compQuick++;
			int temp = vetor[i];
			vetor[i] = vetor[enderecoMaior];
			vetor[enderecoMaior]  = temp ;
			enderecoMaior++;
		    movQuick++;
		}
	}
	int temp  = vetor[enderecoMaior];
	vetor[enderecoMaior] = vetor[tamanho - 1];
	vetor[tamanho - 1] = temp ;
	movQuick++;
	if (enderecoMaior > 1)
		quick(vetor, enderecoMaior, comp, tempo, a, tipo, trocas);
	if (tamanho - enderecoMaior - 1 > 1)
		quick(vetor + enderecoMaior + 1, tamanho - enderecoMaior - 1, comp, tempo, a, tipo, trocas);
	*trocas=movQuick;
	*comp=compQuick;
	return mov;
	
}