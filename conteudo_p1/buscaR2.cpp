#include <iostream>
using namespace std;
#define MAX 100

int buscaR2(int n, int v[MAX], int x){
    if (n <= 0){
        return 0; // caso base
    }

    if (v[n-1] == x){
        return 1;
    } 
    
    return buscaR2(n-1, v, x);
}

int main(){
    int v[MAX], n, x;
    cout << "Informe o tamanho do vetor v: ";
    cin >> n;
    cout << "Informe os elementos do vetor n: ";
    for(int i =0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe o valor de x: ";
    cin >> x;
    int resultado = buscaR2(n, v, x);
    if (resultado == 1){
        cout << "Valor encontrado no vetor!" << endl;
    } else{
        cout << "Valor NAO encontrado no vetor!" << endl;
    }

}