#include <iostream>
using namespace std;
#define MAX 100

bool decide(int a[], int n, int x){ //x é um valor qualquer, n é o tamanho do vetor
  if (n <= 0){
    return false;  // caso base
  }
  if (a[n-1] == x){ // compara se o elemento da última posicão do vetor é igual o elemento x;
    return true;
  }

  return decide(a, n-1, x);
}

int main (){
    int a[MAX], x, n;
    cout << "Informe o tamanho do vetor a: ";
    cin >> n;
    cout << "Informe os elementos de a: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Informe o valor a ser encontrado: ";
    cin >> x;
    if (n > 0){
        if(decide(a, n, x)){
            cout <<"Valor encontrado"<< endl;
        } else{
            cout << "Valor não encontrado" << endl;
        }
    }
    return 0;
}