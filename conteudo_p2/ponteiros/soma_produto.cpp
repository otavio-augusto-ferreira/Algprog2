#include <iostream>
using namespace std;
#define MAX 100

void soma_prod(int a, int b, int* soma, int* prod){
    *soma = a + b;
    *prod = a * b;
}

int main () {
    int a, b, soma, prod;
    cout << "Informe a: " << endl;
    cin >> a;
    cout << "Informe b: " << endl;
    cin >> b;
    
    soma_prod(a, b, &soma, &prod);
    cout << "Resultado da soma de a + b: " << soma << endl;
    cout << "Resultado do produto de a X b: " << prod << endl;

    int soma_total = 0;
    int prod_total = 1;

    for(int i = 0; i < n; i++){
        soma_prod(soma_total)
    }

    return 0;
}