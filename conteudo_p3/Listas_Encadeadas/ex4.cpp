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

int* copiar_lista_para_vetor(lsc* lista, int& tamanho_retornado){
    int contador = 0;
    No* atual = lista->inicio;
    while(atual != nullptr){
        contador++;
        atual = atual->prox;
    }

    tamanho_retornado = contador;

    if(contador == 0) return nullptr;

    int* vetor = new int[contador];

    atual = lista->inicio;
    int i = 0;
    while(atual != nullptr){
        vetor[i] = atual->chave;
        i++;
        atual = atual->prox;
    }
    return vetor;
}

int main(){
    lsc minhaLista;
    minhaLista.inicio = nullptr;

    int tamanhoVetor;
    cout << "Quantos elementos voce deseja colocar no seu vetor inicial? ";
    cin >> tamanhoVetor;

    if(tamanhoVetor <= 0){
        cout << "Tamanho invalido!" << endl;
        return 0;
    }

    int* vetor = new int[tamanhoVetor];

    for(int i = 0; i < tamanhoVetor; i++){
        cout << "Digite o valor o vetor[" << i << "]: ";
        cin >> vetor[i];
    }
    cout << "\n --- TESTANDO ITEM (A): Copiar Vetor do Usuario para o Final da Lista ---" << endl;
    copiar_vetor_para_final(&minhaLista, vetor, tamanhoVetor);

    No* atual = minhaLista.inicio;

    cout<< "Lista encadeada gerada: ";
    while(atual != nullptr){
        cout << "[" << atual->chave << "] -> ";
        atual = atual->prox;
    }
    cout << "NULL" << endl;

    delete[] vetor;

    cout << "\n-- TESTANDO ITEM (B): Copiar a Lista de Volta para um Novo Vetor ---" << endl;
    int TamanhoDoVetorRetornado = 0;

    int* novoVetor = copiar_lista_para_vetor(&minhaLista, TamanhoDoVetorRetornado);

    if(novoVetor != nullptr){
        cout << "Vetor criado a partir da lista (Tamanho " << "):" << endl;
        for (int i = 0; i < TamanhoDoVetorRetornado; i++){
            cout << "novoVetor[" << i << "] = " << novoVetor[i] << endl;
        }

        delete[] novoVetor;
    } else {
        cout <<"Erro: A lista estava vazia" << endl;
    }
    cout << "\n-------------------------------------" << endl;
    cout << "Limpando a memoria da lista... Fim do programa" << endl;

    atual = minhaLista.inicio;
    while(atual != nullptr){
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }
    return 0;
}