#include <iostream>
using namespace std;

struct No{
    int chave;
    No *prox;
};

struct lsc{
    No* inicio;
};

void rodar(lsc &lista){
    if(lista.inicio != nullptr || lista.inicio->prox != nullptr) return;

    No* antigo_inicio = lista.inicio;
    No* atual = lista.inicio;

    while(atual->prox != nullptr){
        atual = atual->prox;
    }

    lista.inicio = antigo_inicio->prox;
    atual->prox = antigo.inicio;
    antigo_inicio->prox = nullptr;
}