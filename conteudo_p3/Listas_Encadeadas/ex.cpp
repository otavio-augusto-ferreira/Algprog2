#include <iostream>
using namespace std;

struct No {
    int chave;
    No* proximo;
};

void insere_crescente_lsc(No* &lista, int x){
    No *ant, *atual, *novo;
    novo = new No;
    novo->chave = x;
    ant = nullptr;
    atual = lista; 

    while (atual != nullptr && atual->chave < x) {
        ant = atual;
        atual = atual->proximo; 
    }
    
    novo->proximo = atual; 
    
    if (ant != nullptr) {
        ant->proximo = novo;   
    } else {
        lista = novo;          
    }
}

//Busca não recursiva
No* busca_lsc(No* lista, int x){
    No* p = lista;
    while (p != nullptr && p->chave != x) {
        if (p->chave > x) return nullptr; // Otimização para lista ordenada
        p = p->proximo;
    }
    return p;
}

void remove_lsc(No* &lista, int x){
    No* ant = nullptr;
    No* atual = lista;

    while(atual != nullptr && atual->chave != x){
        if(atual->chave > x){
            ant = atual;
            atual = atual->proximo;
        }

        if(atual == nullptr){
            cout << "-> Erro: Chave" << x << " nao encontrada.\n";
            return;
        }

        if(ant == nullptr){
            lista = atual->proximo;
        } else{
            ant->proximo = atual->proximo;
        }

        delete atual;
        cout << "-> Sucesso: Chave" << x << " removida.\n";
    }
}

void exibe_lista(No* lista){
    No* atual= lista;
    cout << "Lista atual: ";
    while(atual != nullptr){
        cout << "[" << atual->chave << "] ->";
        atual = atual->proximo;
    }
    cout << "nullptr\n";
}

int main() {
    No* minhaLista = nullptr; // Inicializa a lista sem cabeça (vazia)
    int opcao;
    int valor;

    do {
        std::cout << "\n=================================" << std::endl;
        std::cout << "   MENU - LISTA CRESCENTE (LSC)  " << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "1 - Inserir valor (Ordenado)" << std::endl;
        std::cout << "2 - Buscar valor" << std::endl;
        std::cout << "3 - Remover valor" << std::endl;
        std::cout << "4 - Exibir lista" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite o valor para inserir: ";
                std::cin >> valor;
                insere_crescente_lsc(minhaLista, valor);
                std::cout << "-> Valor inserido!\n";
                exibe_lista(minhaLista); // Mostra a lista pro usuário ver a mágica da ordenação
                break;

            case 2:
                std::cout << "Digite o valor para buscar: ";
                std::cin >> valor;
                if (busca_lsc(minhaLista, valor) != nullptr) {
                    std::cout << "-> Encontrado: O valor " << valor << " ESTA na lista.\n";
                } else {
                    std::cout << "-> Nao encontrado: O valor " << valor << " NAO esta na lista.\n";
                }
                break;

            case 3:
                std::cout << "Digite o valor para remover: ";
                std::cin >> valor;
                remove_lsc(minhaLista, valor);
                exibe_lista(minhaLista);
                break;

            case 4:
                exibe_lista(minhaLista);
                break;

            case 0:
                std::cout << "Encerrando o programa..." << std::endl;
                break;

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0);

    // --- Limpeza de Memória antes de fechar o programa ---
    No* atual = minhaLista;
    while (atual != nullptr) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    return 0;
}