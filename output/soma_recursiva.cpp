#include <iostream>
using namespace std;

int soma(int n){
    if (n <= 1){
        return 1;
    }
    return n + soma(n-1);
}


int main(){
    int n;
    cout << "Informe um numero inteiro: ";
    cin >> n; 

    cout << "A soma de 1 ate " << n << " e " << soma(n) << endl;
    return 0;
}