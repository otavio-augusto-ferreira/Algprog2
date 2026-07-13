#include <iostream>
#include <new>
#include <string>
using namespace std;

struct pessoa
{
    string nome;
    int rg;
    struct  pessoa* proximo;
};


void limpaTela(){
    system("CLS");
}

int retornaTamanho(pessoa *ponteiroEncadeada){
    
    if(ponteiroEncadeada->nome == ""){
        return 0;
    }
    
    int tamanho = 0;
    pessoa *p = ponteiroEncadeada;


    while(p != NULL){
        p = p->proximo;
        tamanho++;
    }
    return tamanho++;
}

void imprimeEncadeada(pessoa* ponteiroEncadeada){
    pessoa *p = ponteiroEncadeada;

    while(p != NULL){
        cout << p->nome << "," << p->rg << "\n";
        p = p->proximo;
    }
}

void adcComecoEncadeada(pessoa* &ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = ponteiroEncadeada;

    if(ponteiroEncadeada->nome == ""){
        novoValor->proximo = NULL;
    } else{
        novoValor->proximo = ponteiroEncadeada;
    }
    ponteiroEncadeada = novoValor;

}

int main(){
    int funcaoDesejada = 1;

    //cria o inicio da lista encadeada
    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome= "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "Tavin";
    novoPrimeiroValor->rg = 123;
    novoPrimeiroValor->proximo = NULL;

    ponteiroEncadeada = novoPrimeiroValor;

    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "Nilton";
    novoSegundoValor->rg = 465;
    novoSegundoValor->proximo = NULL;

    novoPrimeiroValor->proximo = novoSegundoValor;


    while(funcaoDesejada < 9 && funcaoDesejada > 0){
        

        cout << "\nOperacoes \n";
        cout << "1 - Insercao de um no node no inicio da lista";
        cout << "2 - Insercao de um node no no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node do fim da lista \n";
        cout << "6 - Retirar um node da posicao N \n";
        cout << "7 - Procurar um node com o campo RG\n";
        cout << "8 - Imprimir a Lista \n";
        cout << "9 - Sair do sistema \n";
        cout << "\nEscolha um numero e pressione ENTER:  \n";
        cout << "\n\nTamanho Atual: " << retornaTamanho(ponteiroEncadeada)<< "\n";
        cin >> funcaoDesejada;

        if(retornaTamanho(ponteiroEncadeada) == 0){
            cout << "\n Lista Vazia";
        } else {
            imprimeEncadeada(ponteiroEncadeada);
        }
        
        string nome;
        int rg;

        switch (funcaoDesejada)
        {
        case 1:
            cout <<"Funcao escolhida: 1 - Insercao de um no node no inicio da lista";
            cout << "\nDigite o nome: ";
            cin >> nome; 
            cout << "Digite o RG: ";
            cin >> rg;

            adcComecoEncadeada(ponteiroEncadeada, nome, rg);

            break;
        
        default:
            break;
        }

        limpaTela();
    }
}