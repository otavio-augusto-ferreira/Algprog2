#include <iostream>
using namespace std;
#define MAX 100

void troca(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int partition(int p, int r, int v[MAX]){
    int x, i, j;
    x = v[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(v[j] <= x){
            i = i + 1;
            troca(v[i], v[j]);
        }
    }
    troca(v[i + 1], v[r]);
    return i + 1;

}

int Partition_Aleatorio(int p, int r, int v[MAX]){
    int indice_aleatorio = (p + r)/2;
    troca(v[indice_aleatorio], v[r]);
    return partition(p, r, v);
}

void quickSort(int p, int r, int v[MAX]){
    int q;
    if (p < r){
        q = Partition_Aleatorio(p, r, v);
        quickSort(p, q - 1, v);
        quickSort(q + 1, r, v);
    }
}

int main(){
    int v[MAX], n;
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    quickSort(0, n-1, v);
    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    } 
    cout << endl;

    return 0;
}