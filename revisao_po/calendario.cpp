#include <iostream>
using namespace std;
#define MAX 100

struct Evento{
    int horario_inicio;
    int duracao;
};

void trocar(Evento &a, Evento &b){
    Evento temporario = a;
    a = b;
    b = temporario;
}

bool vemAntes(Evento a, Evento b){
    if(a.horario_inicio < b.horario_inicio){
        return true;
    }

    if(a.horario_inicio == b.horario_inicio){
        return a.duracao < b.duracao;
    }

    return false;
}

int particionar(Evento v[], int baixo, int alto){
    Evento pivo = v[alto];
    int i = baixo - 1;

    for(int j = baixo; j < alto; j++){
        if(vemAntes(v[j], pivo)){
            i++;
            trocar(v[i], v[j]);
        }
    }
    trocar(v[i+1], v[alto]);
    return i + 1;
}

void quickSort(Evento v[], int baixo, int alto){
    if(baixo < alto){
        int indice_pivo = particionar(v, baixo, alto);

        quickSort(v, baixo, indice_pivo - 1);
        quickSort(v, indice_pivo + 1, alto);
    }
}

int main(){
    int n; 
    cin >> n;

    Evento eventos[MAX];

    for(int i = 0; i < n; i++){
        cin >> eventos[i].horario_inicio >> eventos[i].duracao; 
    }

    quickSort(eventos, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << eventos[i].horario_inicio << " " << eventos[i].duracao << endl;
    }

    return 0;
}