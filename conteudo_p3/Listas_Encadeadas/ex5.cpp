#include <iostream>
using namespace std;

struct No{
    int chave;
    No* prox;
};

struct lsc{
    No* inicio;
};

void copiar_vetor_para_final(lsc* lista, int vetor[], int tamanho){
    if (tamanho <= 0) return;

    No* ultimo = lista->inicio;
    if(ultimo != nullptr){
        while(ultimo->prox != nullptr){
            ultimo = ultimo->prox;
        }
    }

    for(int i = 0; i < tamanho; i++){
        No* novo = new No();
        novo->chave = vetor[i];
        novo->prox = nullptr;
    

        if(lista->inicio == nullptr){
            lista->inicio = novo;
            ultimo = novo;
        }
        else {
            ultimo->prox = novo;
            ultimo = novo;
        }
    }
}

bool listas_sao_iguais(lsc* listaA, lsc* listaB){
    No* pA = listaA->inicio;
    No* pB = listaB->inicio;

    while(pA != nullptr && pB != nullptr){
        if(pA->chave != pB->chave){
            return false;
        }    
    pA = pA->prox;
    pB = pB->prox;
    }

    return (pA == nullptr && pB == nullptr);
}

void imprimir_lista(lsc* lista, string nomeLista){
    No* atual = lista->inicio;
    cout << nomeLista << ": ";
    while(atual != nullptr){
        cout << "[" << atual->chave << "] -> ";
        atual = atual->prox;
    }
    cout << "NULL" << endl;
}

int main(){

    lsc minhaListaA;
    lsc minhaListaB;

    minhaListaA.inicio = nullptr;
    minhaListaB.inicio = nullptr;

    int tamA, tamB;

    cout <<"Informe o numero de elementos da lista A: ";
    cin >> tamA;

    if(tamA > 0){
        int* vetorA = new int[tamA];
        for(int i = 0; i < tamA; i++){
            cout << "Digite o valor para lista A [" << i << "]: ";
            cin >> vetorA[i];
        }
        copiar_vetor_para_final(&minhaListaA, vetorA, tamA);
        delete[] vetorA;
    }
    cout << "\n------------------------------------------------" << endl;

    if(tamB > 0){
        int* vetorB = new int[tamB];
        for(int i = 0; i < tamB; i++){
            cout <<"Digite o valor para lista B [" << i << "]: ";
            cin >> vetorB[i];
        }
        copiar_vetor_para_final(&minhaListaB, vetorB, tamB);
        delete[] vetorB;
    }

    cout << "\n --- REVISANDO AS LISTAS CRIADAS ---" << endl;
    imprimir_lista(&minhaListaA, "Listas A");
    imprimir_lista(&minhaListaB, "Listas B");
    cout << "--------------------------------------" << endl;

    if(listas_sao_iguais(&minhaListaA, &minhaListaB)){
        cout <<"A listas posseum o mesmo conteudo";
    } else{
        cout << "As listas sao diferentes";
    }

    cout << "-------------------------------------" << endl;

    No* atual = minhaListaA.inicio;
    while(atual != nullptr){
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }

    atual = minhaListaB.inicio;
    while(atual != nullptr){
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }

    return 0;
}