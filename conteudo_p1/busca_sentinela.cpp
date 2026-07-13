#include <iostream>
using namespace std;
#define MAX 100

int busca_sentinela(int v[], int n, int x){
    v[n] = x;
    int i = 0;
    while(v[i] != x){
        i++;
    }
    return i;

}

int main (){
    int v[MAX], n, x;
    cout << "Informe o numero de elementos do vetor v: ";
    cin >> n;
    cout << "Informe os elementos do vetor v: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe o valor de x: ";
    cin >> x;
    int resultado = busca_sentinela(v, n, x);
    if (resultado < n){
        cout << "Elemento encontrado no vetor" << endl;
    } else{
        cout << "Elemento nao encontrado no vetor" << endl;
    }
    return 0;
}