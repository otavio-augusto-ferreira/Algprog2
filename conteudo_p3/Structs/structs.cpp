#include <iostream>
#include <string>
#include <new>
using namespace std;

struct fruta{
    string cor;
    string nome;

};


int main (){

    //criando um ponteiro para o struct criado
    fruta *primeriaFruta = new fruta;

    //modificando valores
    primeriaFruta->cor = "Amarela";
    primeriaFruta->nome = "Banana";

    //Exibindo Valores
    cout << "Fruta: " << primeriaFruta->nome << ", Cor: " << primeriaFruta->cor;

    //Criando uma lista de frutas
    fruta *ponteiroListaDeFrutas = new fruta[2];

    ponteiroListaDeFrutas[0].cor = "Vermelho";
    ponteiroListaDeFrutas[0].nome = "Morango";
    ponteiroListaDeFrutas[1].cor = "Verde";
    ponteiroListaDeFrutas[1].nome = "Kiwi";

    for(int i = 0; i < 2; i++){
         cout << "\nFruta: " << ponteiroListaDeFrutas[i].nome << ", Cor: " << ponteiroListaDeFrutas[i].cor;
    }
    return 0;
}
