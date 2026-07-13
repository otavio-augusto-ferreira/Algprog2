#include <iostream>
using namespace std;

void dec2Bin(int n){
    if (n > 1){
        dec2Bin(n/2);
    }

    cout << n % 2;

}

int main(){
    int n;
    cout << "Informe um numero inteiro decimal: ";
    cin >> n;

    if (n < 0){
        cout << "O numero deve ser positivo." << endl;
    } else if (n == 0) {
        cout << "0 em binario e: 0" << endl;
    } else {
        cout << "A representacao binaria de " << n << " e: ";
        dec2Bin(n);
        cout << endl;
    }
    return 0;
}