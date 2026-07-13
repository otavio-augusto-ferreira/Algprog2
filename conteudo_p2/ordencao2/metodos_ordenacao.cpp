#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#ifndef timersub
#define timersub(a, b, res)                           \
  do {                                                \
    (res)->tv_sec = (a)->tv_sec - (b)->tv_sec;        \
    (res)->tv_usec = (a)->tv_usec - (b)->tv_usec;     \
    if ((res)->tv_usec < 0) {                         \
      (res)->tv_sec--;                                \
      (res)->tv_usec += 1000000;                      \
    }                                                 \
  } while (0)
#endif

using namespace std;

#define MAX 100000

//Prototipação
void bubbleSort(int, int[]);
void selectionSort(int, int[]);
void insertionSort(int, int[]);
void mergeSort(int, int, int[]);
void merge(int, int, int, int[]);
void quickSort(int, int, int[]);
int partition(int, int, int[]);
void troca(int& a, int& b);
void imprimeVetor(int, int[]);

int vetB[MAX], vetS[MAX], vetI[MAX], vetM[MAX], vetQ[MAX];
int main()
{
	int n;

	timeval inicio, fim, total;
	long tempo_bubble, tempo_selection, tempo_insertion, tempo_merge, tempo_quick;

	cin >> n;

	srand(time(0));
	for (int i = 0; i < n; i++)
		vetB[i] = vetS[i] = vetI[i] = vetM[i] = vetQ[i] = rand() % 1000;//n - i;

	//imprimeVetor(n, vet);

	gettimeofday(&inicio, 0);
	bubbleSort(n, vetB);
	gettimeofday(&fim, 0);
	timersub(&fim, &inicio, &total);

	tempo_bubble = total.tv_sec * 1000000 + total.tv_usec;

	gettimeofday(&inicio, 0);
	selectionSort(n, vetS);
	gettimeofday(&fim, 0);
	timersub(&fim, &inicio, &total);

	tempo_selection = total.tv_sec * 1000000 + total.tv_usec;

	gettimeofday(&inicio, 0);
	insertionSort(n, vetI);
	gettimeofday(&fim, 0);
	timersub(&fim, &inicio, &total);

	tempo_insertion = total.tv_sec * 1000000 + total.tv_usec;

	gettimeofday(&inicio, 0);
	mergeSort(0, n, vetM);
	gettimeofday(&fim, 0);
	timersub(&fim, &inicio, &total);

	tempo_merge = total.tv_sec * 1000000 + total.tv_usec;

	gettimeofday(&inicio, 0);
	quickSort(0, n - 1, vetQ);
	gettimeofday(&fim, 0);
	timersub(&fim, &inicio, &total);

	tempo_quick = total.tv_sec * 1000000 + total.tv_usec;

	cout << "Tempo Bubble: " << tempo_bubble << " microssegundos\n";
	cout << "Tempo Selection: " << tempo_selection << " microssegundos\n";
	cout << "Tempo Insertion: " << tempo_insertion << " microssegundos\n";
	cout << "Tempo Merge: " << tempo_merge << " microssegundos\n";
	cout << "Tempo Quick: " << tempo_quick << " microssegundos\n";

	//imprimeVetor(n,vet);

	return 0;
}

void bubbleSort(int n, int v[MAX])
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (v[j] > v[j + 1])
				troca(v[j], v[j + 1]);
}

void selectionSort(int n, int v[MAX])
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (v[j] < v[min])
				min = j;

		troca(v[i], v[min]);
	}
}

void insertionSort(int n, int v[MAX])
{
	for (int i = 1; i < n; i++)
	{
		int x = v[i];

		int j;
		for (j = i - 1; j >= 0 && v[j] > x; j--)
			v[j + 1] = v[j];
			
		v[j + 1] = x;
	}
}

//Função que ordena pelo método da intercalação um vetor de p até r-1.
//Parâmetros: p é o índice do início da sequência a ser ordenada
//            r é o índice imediatamente posterior ao fim da sequência
//            v é o vetor a ser ordenado
void mergeSort(int p, int r, int v[MAX])
{
	if (p < r - 1)//Se tiver pelo menos dois elementos
	{
		//Vai "quebrar" o vetor ao meio, computa o índice dessa metade
		int q = (p + r) / 2;
		mergeSort(p, q, v);//Chama mergeSort para primeira metade
		mergeSort(q, r, v);//Chama mergeSort para segunda metade
		merge(p, q, r, v);//Chama merge para intercalar as duas
		                  //metades ordenadas
	}
}

void merge(int p, int q, int r, int v[MAX])
{
	int i, j, k;
	int w[MAX];

	i = p;
	j = q;
	k = 0;

	while (i < q && j < r)//Enquanto houver elementos nas duas subsequências
	{
		if (v[i] < v[j])
		{
			w[k] = v[i];
			i++;
		}
		else
		{
			w[k] = v[j];
			j++;
		}

		k++;
	}

	while (i < q)//Se sobraram elementos na primeira subsequência
		w[k++] = v[i++];

	while (j < r)//Se sobraram elementos na segunda subsequência
		w[k++] = v[j++];

	//Copia os elementos do vetor auxiliar w para o vetor original v
	for (i = p; i < r; i++)
		v[i] = w[i - p];
}

//Função que ordena pelo Quicksort
//Recebe como parâmetros:
//p: índice do primeiro elemento do vetor
//r: índice do último elemento do vetor
//v: vetor
void quickSort(int p, int r, int v[MAX])
{
	int q;

	if (p < r)//Verifica se tem pelo menos 2 elementos no vetor
	{
		q = partition(p, r, v);//Chama partition para obter o índico do pivô
		quickSort(p, q - 1, v);//Chama quicksort para a primeira metade
		quickSort(q + 1, r, v);//Chama quicksort para a segunda metade
	}
	//Se não tiver retorna porque está trivialmente ordenado
}

//Função que particiona o vetor em torno do pivô. O pivô estará na
//posição correta ao final e seu índice será retornado. Todos os
//elementos maiores ou iguais a ele estarão à sua esquerda e os
//menores à dua direita.
int partition(int p, int r, int v[MAX])
{
	int i, j, x;

	i = p -1;
	x = v[r];//Escolhe o último elemento como o pivô

	for (j = p; j < r; j++)
	{
		if (v[j] <= x)
		{
			i++;
			troca(v[i], v[j]);
		}
	}
	troca(v[i + 1], v[r]);

	return i + 1;
}

void troca(int& a, int& b)
{
	int aux;

	aux = a;
	a = b;
	b = aux;
}

void imprimeVetor(int n, int v[MAX])
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << "\n\n";
}