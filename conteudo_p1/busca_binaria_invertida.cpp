#include <iostream>
using namespace std;
#define MAX 100

bool busca_binaria_invertida(int v[MAX], int inicio, int fim, int x){
    if (inicio > fim){
        return false;
    }
    int meio = (fim+inicio)/2;
    if (x == v[meio]){
        return true;
    }
    if (x > v[meio]){
        return busca_binaria_invertida(v, inicio, meio-1, x);
    } else{
        return busca_binaria_invertida(v, meio+1, fim, x);
    }

}

int main(){
    int v[MAX], n, x;
    cout << "Tamanho do vetor v: ";
    cin >> n;
    cout << "Valores do vetor v: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe o valor de x: ";
    cin >> x;
    if (busca_binaria_invertida(v, 0, n-1, x)){
        cout << "Valor encontrado no vetor!" << endl;
    } else{
        cout << "Valor nao encontrado no vetor!" << endl;
    }

    return 0;
}