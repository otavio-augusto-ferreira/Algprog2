#include <iostream>
using namespace std;
#define MAX 100

void matriz(int *p, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << *(p + (i * MAX + j)) << " ";
        }
        cout << endl;
    }
}

int main(){
    int linha, coluna, m[MAX][MAX];
    
    cin >> linha;
    cin >> coluna;

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> m[i][j];
        }
    }
    matriz(&m[0][0], linha, coluna);
}