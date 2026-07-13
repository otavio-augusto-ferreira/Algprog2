#include <iostream>
using namespace std;
#include <climits>

struct PilhaSeq{
    int* vetP;
    int topo;
    int capacidade;
};

PilhaSeq* cria_PilhaSeq(int maxTam){
    PilhaSeq* pilha = new PilhaSeq;
    pilha->vetP = new int[maxTam];
    pilha->capacidade = maxTam;
    pilha->topo = -1;
    return pilha;
}

void empilhar(PilhaSeq* pilha, int novo){
    if(pilha->topo != pilha-> capacidade-1){
        pilha->topo++;
        pilha->vetP[pilha->topo] = novo;
    } else {
        cout << "Pilha cheia!\n";
    }
}


int desempilhar(PilhaSeq* pilha){
    int x = INT_MAX;
    if(pilha->topo != -1){
        x = pilha->vetP[pilha->topo];
        pilha->topo --;
    }
    else{
        cout <<"Pilha vazia!\n";
    }
    return x;
}

void exibe_pilha(PilhaSeq* pilha){
    if (pilha->topo == -1){
        cout << "[ ] (vazia)" << endl;
        return;
    }
    cout << "[ ";
    for(int i = 0; i <= pilha->topo; i++){
        cout << pilha->vetP[i] << " ";
    }
    cout << "] <- Topo" << endl;
}

int main(){
    PilhaSeq* minhaPilha = cria_PilhaSeq(20);

    cout << "Executando a sequencia do Exercicio 1:\n\n";

    empilhar(minhaPilha, 5);
    empilhar(minhaPilha, 3);
    desempilhar(minhaPilha);
    empilhar(minhaPilha, 2);
    empilhar(minhaPilha, 8);
    desempilhar(minhaPilha);
    desempilhar(minhaPilha);
    empilhar(minhaPilha, 9);
    empilhar(minhaPilha, 1);
    desempilhar(minhaPilha);
    empilhar(minhaPilha, 7);
    empilhar(minhaPilha, 6);
    desempilhar(minhaPilha);
    desempilhar(minhaPilha);
    empilhar(minhaPilha, 4);
    desempilhar(minhaPilha);
    desempilhar(minhaPilha);

    //Exibe o resultado final após todas as operações
    cout << "Resultado final impresso pelo codigo: " << endl;
    exibe_pilha(minhaPilha);

    delete[] minhaPilha->vetP;
    delete minhaPilha;

    return 0;

}