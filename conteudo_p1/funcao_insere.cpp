#include <iostream>
using namespace std;
#define MAX 100

int insere(int &n, int v[MAX], int k, int y){
    if (n >= MAX){
        return -1;
    }
    if (k < 0 || k > n){
        return -2;
    }
    for(int i = n; i > k; i--){
        v[i] = v[i-1];
    }
    v[k] = y;
    n = n+1;
    return n;
}

int main(){
    int v[MAX], n, k, y;
    cout << "Informe o tamanho do vetor v: ";
    cin >> n;
    cout << "Informe os elementos do vetor v: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout <<"Informe o indice k: ";
    cin >> k;
    cout <<"Informe o valor de k[y]: ";
    cin >> y;
    int resultado = insere(n, v, k, y);
    for(int i = 0; i < resultado; i++){
        cout << v[i] << endl;
    }
    return 0;
}