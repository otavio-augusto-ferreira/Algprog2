#include <iostream>
using namespace std;
#define MAX 100

int somaVetor(int num, int* vet){
    int soma = 0;
    int i = 0;
    int q = num;
    int* p = vet;
    while(i < q){
        soma += *p;
        p++;
        i++;
    }
    return soma;
}

int main(){
    int num, vet[MAX];
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> vet[i];
    }
    cout << somaVetor(num, vet) << endl;
}