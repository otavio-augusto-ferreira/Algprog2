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
    x = v[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(v[j] <= x){
            i = i + 1;
            troca(v[i], v[j]);
        }
    }
    troca(v[i+1], v[r]);
    return i+1;
}

void quickSort(int p, int r, int v[MAX]){
    if(p < r){
        int q = partition(p, r, v);
        quickSort(p, q-1, v);
        quickSort(q+1, r, v);
    }   
}

int main () {
    int v[MAX], n;
    cout << "Tamanho do vetor" << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    quickSort(0, n-1, v);
    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}