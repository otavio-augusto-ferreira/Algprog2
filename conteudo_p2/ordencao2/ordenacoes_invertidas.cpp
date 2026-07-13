#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

// Definição da macro timersub para compatibilidade em ambientes Windows/VS
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

// Prototipação
void bubbleSort(int, int[]);
void selectionSort(int, int[]);
void insertionSort(int, int[]);
void mergeSort(int, int, int[]);
void merge(int, int, int, int[]);
void quickSort(int, int, int[]);
int partition(int, int, int[]);
void troca(int& a, int& b);
void imprimeVetor(int, int[]);

// Vetores globais para evitar Stack Overflow
int vetB[MAX], vetS[MAX], vetI[MAX], vetM[MAX], vetQ[MAX];

int main()
{
    int n;
    timeval inicio, fim, total;
    long tempo_bubble, tempo_selection, tempo_insertion, tempo_merge, tempo_quick;

    cout << "Digite o tamanho do vetor (n): ";
    if (!(cin >> n) || n > MAX) return 0;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        int r = rand() % 1000;
        vetB[i] = vetS[i] = vetI[i] = vetM[i] = vetQ[i] = r;
    }

    // Medição BubbleSort
    gettimeofday(&inicio, 0);
    bubbleSort(n, vetB);
    gettimeofday(&fim, 0);
    timersub(&fim, &inicio, &total);
    tempo_bubble = total.tv_sec * 1000000 + total.tv_usec;

    // Medição SelectionSort
    gettimeofday(&inicio, 0);
    selectionSort(n, vetS);
    gettimeofday(&fim, 0);
    timersub(&fim, &inicio, &total);
    tempo_selection = total.tv_sec * 1000000 + total.tv_usec;

    // Medição InsertionSort
    gettimeofday(&inicio, 0);
    insertionSort(n, vetI);
    gettimeofday(&fim, 0);
    timersub(&fim, &inicio, &total);
    tempo_insertion = total.tv_sec * 1000000 + total.tv_usec;

    // Medição MergeSort
    gettimeofday(&inicio, 0);
    mergeSort(0, n, vetM);
    gettimeofday(&fim, 0);
    timersub(&fim, &inicio, &total);
    tempo_merge = total.tv_sec * 1000000 + total.tv_usec;

    // Medição QuickSort
    gettimeofday(&inicio, 0);
    quickSort(0, n - 1, vetQ);
    gettimeofday(&fim, 0);
    timersub(&fim, &inicio, &total);
    tempo_quick = total.tv_sec * 1000000 + total.tv_usec;

    // Resultados formatados em milissegundos (ms) como pedido
    cout << "\n--- Resultados (Ordenacao Decrescente) ---\n";
    cout << "Tempo Bubble: " << tempo_bubble / 1000.0 << " ms\n";
    cout << "Tempo Selection: " << tempo_selection / 1000.0 << " ms\n";
    cout << "Tempo Insertion: " << tempo_insertion / 1000.0 << " ms\n";
    cout << "Tempo Merge: " << tempo_merge / 1000.0 << " ms\n";
    cout << "Tempo Quick: " << tempo_quick / 1000.0 << " ms\n";

    return 0;
}

// Funções de Ordenação Decrescente

void bubbleSort(int n, int v[MAX]) {
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (v[j] < v[j + 1]) // Menor vai para o fim
                troca(v[j], v[j + 1]);
}

void selectionSort(int n, int v[MAX]) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] > v[max_idx]) // Busca o maior
                max_idx = j;
        troca(v[i], v[max_idx]);
    }
}

void insertionSort(int n, int v[MAX]) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j;
        for (j = i - 1; j >= 0 && v[j] < x; j--) // Desloca se for menor que o pivô
            v[j + 1] = v[j];
        v[j + 1] = x;
    }
}

void mergeSort(int p, int r, int v[MAX]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        merge(p, q, r, v);
    }
}

void merge(int p, int q, int r, int v[MAX]) {
    int i = p, j = q, k = 0;
    static int w[MAX]; // Auxiliar estático para não sobrecarregar a pilha

    while (i < q && j < r) {
        if (v[i] > v[j]) w[k++] = v[i++]; // Pega o maior primeiro
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (i = p; i < r; i++) v[i] = w[i - p];
}

void quickSort(int p, int r, int v[MAX]) {
    if (p < r) { // Condição de parada corrigida
        int q = partition(p, r, v);
        quickSort(p, q - 1, v);
        quickSort(q + 1, r, v);
    }
}

int partition(int p, int r, int v[MAX]) {
    int i = p - 1, x = v[r];
    for (int j = p; j < r; j++) {
        if (v[j] >= x) { // Maiores que o pivô à esquerda
            i++;
            troca(v[i], v[j]);
        }
    }
    troca(v[i + 1], v[r]);
    return i + 1;
}

void troca(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

void imprimeVetor(int n, int v[MAX]) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n\n";
}