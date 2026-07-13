#include <iostream>
using namespace std;
#define MAX 100

void min_max(int n, int v[MAX], int* max, int* min){
    *max = v[0];
    *min = v[0];
    
    for(int i = 1; i < n; i++){  //podemos inicilizar em 1, pois o 0 já foi testado
        if (v[i] > *max){
            *max = v[i];
        }

        if (v[i] < *min){
            *min = v[i];
        }
    }
}

int main() {
    int v[MAX], n;
    int maior, menor;

    cout << "Informe o tamanho do vetor: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    min_max(n, v, &maior, &menor);
    cout << "O maior elemento eh: " << maior << endl;
    cout << "O menor elemento eh: " << menor << endl;

    return 0;
}