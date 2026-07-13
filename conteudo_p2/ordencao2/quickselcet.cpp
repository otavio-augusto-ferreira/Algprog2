#include <iostream>
using namespace std;

#define MAX 100

void troca(int& a, int&b){
    int aux = a; 
    a = b;
    b = aux;
}

int partition(int v[MAX], int inicio, int fim){
    int pivo = v[fim];
    int i = inicio;

    for(int j = inicio; j < fim; j++){
        if (v[j] <= pivo){
            troca(v[i], v[j]);
            i++;
        }
    }
    troca(v[i], v[fim]);
    return i;
}

int quickSelect (int v[MAX], int inicio, int fim, int k){
    if (k > 0 && k <= (fim - inicio + 1)){
        int posicaoPivo = partition(v, inicio, fim);

        if (posicaoPivo - inicio == k - 1){
            return v[posicaoPivo]; 
        }

        if (posicaoPivo - inicio == k - 1){
            return v[posicaoPivo];
        }
        if (posicaoPivo - inicio > k - 1){
            return quickSelect(v, inicio, posicaoPivo - 1, k);
        }
        return quickSelect(v, posicaoPivo + 1, fim, k - (posicaoPivo - inicio + 1));
    }
    return -1;
}

int main(){
    int v[MAX], n, k;
    cout << "Tamanho do vetor: ";
    cin >> n;
    cout << "Informe os elmentos do vetor: ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    cin >> k;

    int resultado = quickSelect(v, 0, n-1, k);
    if(resultado != -1){
        cout <<"O menor elemento é: " << resultado << endl;
    } else {
        cout << "K invalido!" << endl;
    }
    return 0;
}