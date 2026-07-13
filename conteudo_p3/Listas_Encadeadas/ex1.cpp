#include <iostream>
using namespace std;

struct Celula{
    int conteudo; // número guardado na célula
    Celula* proximo; // endereço da próxima célula
};

void exibeLista(Celula* inicio){
    Celula* atual = inicio;

    while (atual != nullptr){
        cout << "[" << atual->conteudo << "] -> ";
        atual = atual->proximo;
    }
    cout << "NULL (fim da lista)" << endl;
}

void removeCelula(Celula* p){
    if (p == nullptr || p->proximo == nullptr) {
        return;
    }
    
    Celula* vagaoDaFrente = p->proximo;
    p->conteudo = vagaoDaFrente->conteudo;
    p->proximo = vagaoDaFrente->proximo;
    delete vagaoDaFrente;
}

int main(){
    Celula* v1 = new Celula{20, nullptr};
    Celula* v2 = new Celula{4, nullptr};
    Celula* v3 = new Celula{5, nullptr};
    Celula* v4 = new Celula{19, nullptr};
    Celula* v5 = new Celula{47, nullptr};
    
    v1->proximo = v2;
    v2->proximo = v3;
    v3->proximo = v4;
    v4->proximo = v5;

    exibeLista(v1);

    Celula* p = v3;
    removeCelula(p);

    cout << "Lista modificada: " << endl;
    exibeLista(v1);

    delete v1;
    delete v2;
    delete v3;
    delete v5;

    return 0;
}