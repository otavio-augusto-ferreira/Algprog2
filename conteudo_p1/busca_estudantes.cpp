#include <iostream>
using namespace std;
#define MAX 100

typedef struct {
    char nome[MAX];
    int num;
} Estudante;


string Busca_Binaria(Estudante v[], int n, int num_procurado){
    int inicio = 0;
    int fim = n-1;
    while (inicio <= fim){
        int meio = (inicio+fim)/2;

        if (v[meio].numero == num_procurado){
            return v[meio].nome;
        }

        if (v[meio].nome < num_procurado){
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return "";
}

int main(){
    int main() {
    int n;

    << "Quantos estudantes voce quer cadastrar? ";
    cin >> n;

    // Criamos o vetor com o tamanho que o usuario escolheu
    // Nota: Em C++ acadêmico, o tamanho deve ser constante ou usar alocação dinâmica.
    // Para simplificar, vamos usar um tamanho máximo ou assumir que seu compilador aceita VLA.
    Estudante lista[100]; 
    if (n > 100) n = 100; // Proteção para não quebrar o programa

    std::cout << "--- Cadastro (Digite em ordem crescente de numero!) ---" << std::endl;

    for (int i = 0; i < n; i++) {
        << "Digite o numero do estudante " << i + 1 << ": ";
        >> lista[i].numero;
        
        << "Digite o nome do estudante " << i + 1 << ": ";
        >> lista[i].nome;
        cout << "--------------------------------" << endl;
    }

    int busca;
    cout << "\nQual numero de estudante voce deseja procurar? ";
    cin >> busca;

    string resultado = buscaBinaria(lista, n, busca);

    if (resultado != "") {
        cout << "Sucesso! O nome do estudante " << busca << " e: " << resultado << endl;
    } else {
        cout << "Ops! Esse numero nao esta na nossa lista." << endl;
    }

    return 0;
}