#include <iostream>
using namespace std;

struct No{
    int chave;
    No* prox;
};

struct lsc{
    No* inicio;
};

void inserir_inicio (lsc* lista, int valor){
    No* novo = new No();
    novo->chave = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

No* busca_lsc(lsc* lista, int x){
    No* p = lista->inicio;

    while(p != nullptr && p->chave != x){
        p = p->prox;
    }
    return p;
}

No* encontra_minimo_lsc(lsc* lista){
    
    if(lista == nullptr || lista->inicio == nullptr){
        return nullptr;
    }

    No* menor = lista->inicio;
    No* atual = menor->prox;

    while(atual != nullptr){
        if(atual->chave < menor->chave){
            menor = atual;
        }
        atual = atual->prox;
    }

    return menor;
}

void imprimir_lista(lsc* lista){
    No* atual = lista->inicio;
    cout << "Lista atual: ";
    while (atual != nullptr){
        cout<< "[" << atual->chave << "] -> ";
        atual = atual->prox;
    }
    
    cout << "NULL" << endl; 
}

int main(){

    lsc minhaLista;
    minhaLista.inicio = nullptr;
    
    int quantidade;
    cout << "Quantos numeros deseja inserir? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++){
        int valor;
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> valor;
        inserir_inicio(&minhaLista, valor);
    }

    cout << "\n--------------------------------" << endl;
    imprimir_lista(&minhaLista);

    No* noMinimo = encontra_minimo_lsc(&minhaLista);
    if(noMinimo != nullptr){
        cout << "O menor eh: " << noMinimo->chave << endl;
    }

    cout << "------------------" << endl;

    int valorBusca;
    cout << "\nDigite um valor para buscar na lista: ";
    cin >> valorBusca;

    No* noEncontrado = busca_lsc(&minhaLista, valorBusca);

    if(noEncontrado != nullptr){
        cout << "Sucesso! O valor " << valorBusca << " foi encntrado no endereco de memoria: " << noEncontrado << endl;
    } else {
        cout << "O valor " << valorBusca << "nao existe na lista." << endl;
    }

    cout << "---------------------" << endl;
    No* atual = minhaLista.inicio;
    while (atual != nullptr){
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }

    return 0;
}
