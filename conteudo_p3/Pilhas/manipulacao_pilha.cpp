#include <iostream>
using namespace std;
#define MAX 10


void imprime_vetor(int vetor[MAX]){
    for(int i = 0; i < MAX; i++){
        cout << vetor[i] << "-";
    }
}

void pilha_push(int pilha[MAX], int valor, int* topo){
    if(*topo == MAX - 1){
        cout << "Pilha Cheia!!";
    } else{
        *topo = *topo + 1;
        pilha[*topo] = valor;
    }
}

bool pilha_vazia(int topo){
    if(topo == -1){
        return true;
    } else{
        return false;
    }
}

int main (){
    int pilha[MAX] = {0,0,0,0,0,0,0,0,0,0};
    int topo = -1;

    imprime_vetor(pilha);

    pilha_push(pilha, 5, &topo);

    imprime_vetor(pilha);


}