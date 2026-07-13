#include <iostream>
using namespace std;
#define MAX 100

void troca(int& a, int& b){
    int aux = a;
    a = b; 
    b = aux;
}
int partition(int p, int r, int v[MAX]){
    int x, i, j;
    x = v[r]; //Escolhe o último elemento para pivô 
    i = p - 1;
    for(j = p; j < r; j++){
        if (v[j] <= x){
            i = i + 1; // Cria espaço para o elemento
            troca(v[i], v[j]);
        }
    }
    troca(v[i+1], v[r]); // Coloca o pivô na posição correta
    return i+1; //Retorna o índice em que o pivô foi colocado
}

void quickSort(int p, int r, int v[MAX]){
    int q;
    if (p < r){
        q = partition(p, r, v);
        quickSort(p, q-1, v);
        quickSort(q+1, r, v);
    }
}


int main(){
    int v[MAX] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int n = 12;

    cout << "Vetor original" << endl;
    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    quickSort(0, n-1, v);
    cout << "Vetor ordenado" << endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    return 0;
}