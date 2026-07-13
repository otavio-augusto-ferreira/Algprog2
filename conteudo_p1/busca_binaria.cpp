#include <iostream>
using namespace std;
#define MAX 100

bool busca_binaria(int v[MAX], int inicio, int fim, int x){
    if (inicio > fim){
        return false;
    }
    int meio = (inicio+fim)/2;
    if(x == v[meio]){
        return true;
    }
    if (x < v[meio]){
        return busca_binaria(v, inicio, meio-1, x);
    } else {
        return busca_binaria(v, meio+1, fim, x);
    }
}

int main (){
    int n, v[MAX], inicio, fim, x;
    cout << "Informe o tamanho do vetor v: ";
    cin >> n;
    cout << "Informe os valores do vetor v: ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe o valor de a ser encontrado: ";
    cin >> x;
    
    if(busca_binaria(v, 0, n-1, x)){
        cout << "Valor encontrado no vetor!" << endl;
    } else{
        cout << "Valor nao encontrado no vetor!" << endl;
    }

    return 0;
}