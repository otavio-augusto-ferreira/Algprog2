#include <iostream>
using namespace std; 

struct Celula{
    int dado;
    Celula* proximo;
};

void inserirInicio(Celula* &inicio, int valor){
    Celula* nova = new Celula();
    nova->dado = valor;
    nova->proximo = inicio;
    inicio = nova;
}

int contar_celulas(Celula* inicio){
    int contador = 0;
    Celula* atual = inicio;
    
    while(atual != nullptr){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

int main(){
    Celula* minhaLista = nullptr;
    int valorUsuario;


    cout << "--- Cadastro de Numeros na Lista ---" << endl;

    while(true){
        cout << "Digite um valor inteiro (ou -1 para encerrar): ";
        cin >> valorUsuario;

        if(valorUsuario == -1){
            break;
        }
        
        inserirInicio(minhaLista, valorUsuario);
    }

    int total = contar_celulas(minhaLista);
    cout << "\nVoce encerrou a insercao." << endl;
    cout << "O numero total de celulas inseridas foi: " << total << endl;
    
    Celula* atual = minhaLista;
    while (atual != nullptr){
        Celula* proxima = atual->proximo;
        delete atual;
        atual = proxima;
    }

    return 0;
}