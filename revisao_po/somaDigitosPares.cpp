#include<iostream>
using namespace std;
#define MAX 100

int somaDigitosPares(int numero){
    if(numero == 0) return 0;

    int ultimoDigito = numero % 10;

    int restoDoNumero = numero / 10;

    if(ultimoDigito % 2 == 0){
        return ultimoDigito + somaDigitosPares(restoDoNumero);
    } else {
        return somaDigitosPares(restoDoNumero);
    }
}

int main(){
    int numero;

    cin >> numero;

    cout << somaDigitosPares(numero) << endl;


}