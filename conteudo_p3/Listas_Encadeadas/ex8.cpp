#include <iostream>
using namespace std;

struct No{
    int chave;
    No* prox;
};

struct lsc{
    No* inicio;
};

void concatena(lsc* lista1, lsc* lista2, lsc* lista3){
    No* atual1 = lista1->inicio;
    No* atual2 = lista2->inicio;

    No aux;
    No *ultimo3 = &aux;

    while(atual1 != nullptr && atual2 != nullptr){
        if(atual1->chave <= atual2->chave){
            ultimo3->prox = atual1;
            atual1 = atual1->prox;
        } else{
            ultimo3->prox = atual2;
            atual2 = atual2->prox;
        }
        ultimo3 = ultimo3->prox;
    }

    if(atual1 != nullptr){
        ultimo3->prox = atual1;
    } else {
        ultimo3->prox = atual2;
    }

    lista3->inicio = aux.prox;

    lista1->inicio = nullptr;
    lista2->inicio = nullptr;
}