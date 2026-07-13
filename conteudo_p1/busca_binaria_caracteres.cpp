#include <iostream>
using namespace std;
#define MAX 100

int busca_binaria_caracteres(string v[MAX], int inicio, int fim, string x){
    if (inicio > fim){
        return -1;
    }
    int meio = (inicio + fim)/2;

    if (x == v[meio]){
        return meio;
    }
    if (x > v[meio]){
        return busca_binaria_caracteres(v, meio + 1, fim, x);
    } else {
        return busca_binaria_caracteres(v, inicio, meio - 1, x);
    }
}

int main (){
    string v[MAX], x;
    int n;
    cout << "Informe o tamanho do vetor v: ";
    cin >> n;
    cout << "Informe os elementos do vetor v: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe a palavra que busca: ";
    cin >> x;
    int k = busca_binaria_caracteres(v, 0, n-1, x);
    if (k != -1){
        cout << "Palavra encontrada! Localizada no indicie: "<< k << endl;
    } else {
        cout << "Palavra nao encontrada no vetor" << endl;
    }

    return 0;
}