#include <iostream>
using namespace std;
#define MAX 100

void merge(int p, int q, int r, int v[MAX]){
    int i, j, k;
    int w[MAX];
    i = p; // começo da primeira metade
    j = q; // começo da segunda metade
    k = 0;

    // Enquanto houver elementos nas duas metades, comparamos
    while (i < q && j < r){
        if (v[i] <= v[j]){
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
        k++;
    }
    // Se sobrou algo na primeira metade, apenas copia
    while (i < q){
        w[k] = v[i];
        i++;
        k++;
    }
    // se sobrou algo na segunda metade, apenas copia
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }

    // move os elementos de vetor auxiliar de volta para o vetor original v
    for (i = p; i < r; i++){
        v[i] = w[i-p];
    }
}

void mergeSort(int p, int r, int v[MAX]){
    // Se o intervalo tem mais de um elemento
    if (p < r-1){
        int q = (p + r) / 2; // Encontra o meio
        mergeSort(p, q, v); // Divide a esquerda
        mergeSort(q, r, v); // Divide a direita
        merge(p, q, r, v); // Junta tudo ordenado
    }
}

int main (){
    int v[MAX] = {3, 41, 52, 26, 38, 57, 9, 49};
    int n = 8;
    cout << "Vetor original" << endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    mergeSort(0, n, v);
    cout << "Vetor ordenado" << endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}