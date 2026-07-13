#include <iostream>
using namespace std;

int potR(int x, int n){
    if (n == 0){
        return 1;
    } else{
        return x * potR(x, n-1);
    }
}

int main(){
    int n, x;
    cout << "Informe o valor de n: ";
    cin >> n;
    cout << "Informe o valor de x: ";
    cin >> x;
    cout << potR(x, n) << endl;

    return 0;
}