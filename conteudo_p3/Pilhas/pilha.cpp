#include <iostream>
using namespace std;

struct No{
    int chave;
    No *prox;
};

struct lsc{
    No *inicio;
};

void empilhar(lsc *pilha, int valor){
    No* novo = new No();
    novo->chave = valor;

    novo->prox = pilha->inicio;
    pilha.inicio = novo;
}

int desempilhar(lsc* pilha){
    if(pilha->inicio == nullptr){
        cout << "Pilha vazia"<< endl;
        return -1;
    }

    No *aux = pilha->inicio;
    int valor = aux-> chave;

    pilha->inicio = pilha->inicio->prox;
    delete aux;
    return valor;

}