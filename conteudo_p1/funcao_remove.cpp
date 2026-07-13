#include <iostream>
using namespace std;
#define MAX 100

int remove_R(int &n, int v[MAX], int k){
    if(k < 0 || k >= n){
        return n; // caso base
    } 
    for(int i = k; i < n-1; i++){
        v[i] = v[i+1];
    }
    n = n-1; // decrementa a variável original
    return n; // retorna o valor atualizado
}

int main (){
    int v[MAX], n, k;
    cout << "Informe o tamanho do vetor: ";
    cin >> n;
    cout << "Informe os valores de n: ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Informe o valor de k: ";
    cin >> k;

    int resultado = remove_R(n, v, k);
    for (int i = 0; i < resultado; i++){
        cout << v[i] << endl;
    }
    return 0;
}