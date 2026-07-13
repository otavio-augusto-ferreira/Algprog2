#include <iostream>
using namespace std;
#define MAX 100

void insertion_sort(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j;
        for(j = i-1; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
}

int main(){
    int v[MAX], n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    insertion_sort(v, n);

    int soma_padrao = v[0] + v[n-1];
    bool balanceada = true;

    int inicio = 0;
    int fim = n - 1; 

    while(inicio < fim){
        if(v[inicio] + v[fim] != soma_padrao){
            balanceada = false;
            break;
        }
        inicio++;
        fim--;
    }

    if(balanceada) {
        cout << "Balanceada" << endl;
    } else {
        cout << "Desbalanceada" << endl;
    }

    return 0;
}