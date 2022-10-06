#include <iostream>

using namespace std;


void bubbleSort (int *vetor, int n)
{
	int i, j, aux;
	for (i = n - 1; i > 0; i--)
	{

		for (j = 0; j < i; j++)
		{

			if (vetor[j] > vetor[j + 1])
			{
				aux = vetor[j];
				vetor[j]    = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}
void insertionSort(int vetor[], int num)
{

	int i, j, aux;

	for( i = 1; i < num; i++)
	{
		aux = vetor[i];
		j = i - 1;
		while((j >= 0) && (aux < vetor[j]))
		{
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = aux;
	}


}
void quickSort ( int Lista[] , int esquerda , int direita )
{
	int tmp , i = esquerda , j = direita - 1;
	int pivo = Lista [( esquerda + direita ) / 2 ];

	while ( i <= j )
	{
		while ( Lista [ i ] < pivo )
			i ++;
		while ( Lista [ j ] > pivo )
			j--;
		if ( i <= j )
		{
			tmp = Lista[i];
			Lista[i] = Lista [j];
			Lista [j] = tmp ;
			i++;
			j--;
		}
	}
	/*recursao*/
	if (esquerda < j )
		quickSort ( Lista , esquerda , j ) ;
	if ( i < direita )
		quickSort ( Lista , i , direita ) ;
}

void selectionSort(int Vet[], int n)
{

	int Menor, aux;

	for(int i = 0; i < n - 1; i++)
	{
		Menor = i;
		for(int j = i + 1 ; j < n ; j++)
		{
			if(Vet[Menor] > Vet[j])
				Menor = j;
		}
		if(i != Menor)
		{
			aux = Vet[i];
			Vet[i] = Vet[Menor];
			Vet[Menor] = aux;
		}
	}
}


int main ()
{
	int num = 5;
	int vetor[num];
	vetor[0] = 4;
	vetor[1] = 3;
	vetor[2] = 5;
	vetor[3] = 1;
	vetor[4] = 2;

	for(int j = 0; j < 5; j++)
	{

		cout << vetor[j] << " ";

	}
	cout << endl;
	selectionSort(vetor, num);



	for(int j = 0; j < 5; j++)
	{
		cout << vetor[j] << " ";

	}

	return 0;
}
