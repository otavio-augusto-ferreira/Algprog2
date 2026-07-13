#include <iostream>
using namespace std;
#include <new>

int main() {
     //definindo variáveis
    int linhas, colunas, i, j;
    int **matriz;

    cout << "Digite o numero de linhas: ";
    cin >> linhas;
    cout << "Digite o numero de colunas: ";
    cin >> colunas;

    matriz = (int **) new int[linhas];

    //Alocando memória para as colunas de cada linha
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) new int[colunas];
    } 

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            matriz[i][j] = i;
            cout << matriz[i][j];
        }
        cout << endl;
    }

    free(matriz);

    return 0;
}