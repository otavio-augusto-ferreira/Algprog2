#include <iostream>
using namespace std;
#define MAX 100

void inverte(int v[], int n, int i){
   if (i >= n-1){
    return;
   }
   int aux = v[i];
   v[i] = v[n-1];
   v[n-1] = aux;

   inverte(v, n-1, i+1);

}

int main (){
    int v[MAX], n, i;
    cout << "Informe o numero de elementos do vetor v: ";
    cin >> n;
    cout << "Informe os elementos de n: ";
    for (i = 0; i < n; i++){
        cin >> v[i];
    }
    inverte(v, n, 0);
    cout << "Vetor invertido" << endl;
    for (i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    return 0;
}