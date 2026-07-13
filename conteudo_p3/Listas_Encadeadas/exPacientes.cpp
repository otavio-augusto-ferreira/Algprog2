#include <iostream>
using namespace std;

//definindo estruturas
struct Paciente 
{
    string nome;
    string cpf;
    int idade;
    int prioridade;
};

struct No
{
    Paciente pac;
    No* prox;
};

struct Fila{
    No* inicio;
    No* fim;

};

Fila* criaFilaVazia(){
    Fila* f = new Fila;

    f->inicio = f->fim = nullptr;

    return f;
}

Paciente* criarPaciente(){
    Paciente* p = new Paciente();
    getline(cin, p->nome);
    getline(cin, p->cpf);
    cin >> p->idade;
    cin >> p->prioridade;
    cin >> p->idade;

    return p;

}

void enfileirar(Fila* f, Paciente* p){
    No* novo = new No;
    novo->pac = p;
    novo->prox = nullptr;
    
    if(f->fim)
    {
        f->fim->prox = novo;
        f->fim = novo;
    } else{
        f->inicio = f->fim = novo;
    }
}

void desenfileira(Fila* f){
    No* ptr = f->inicio;
    if(ptr){
        f->inicio = f->inicio->prox;
        if(f->inicio == nullptr)// a fila ficou vazia
        f->fim = nullptr;

        cout << "Paciente Removido\n";
        cout << ptr->pac->cpf << endl << ptr->pac.nome << " Idade: " << ptr->pac->idade 
        << "Prioridade: " << ptr->pac->prioridade;
        else{
            cout << "A fila ficou vazia\n";
        }
    }
}

void exibirFila(Fila* f){
    for (No* ptr = f->inicio; ptr; ptr = ptr->prox){
        cout << ptr->pac.cpf << endl << ptr->pac.nome << " Idade: " << ptr->pac.idade 
        << "Prioridade: " << ptr->pac.prioridade;
    }
}

int main(){
    Fila* fila;
    fila = criaFilaVazia();
    
    //Criando paciente
    Paciente* p = criarPciente();
    enfileirar(fila, p);

    exibirFila(fila);

    return 0;

}