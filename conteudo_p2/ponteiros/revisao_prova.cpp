#include <iostream>
using namespace std;
#define MAX 100

struct Aluno {
    const char* nome;
    double notas[BIMESTRES][PROVAS];
    double mediaGeral;
};

void calcularMedia(Aluno* aluno){
    double soma = 0;
    for(int i = 0; i < BIMESTRES; i++){
        for(int j = 0; j < PROVAS; j++){
            soma += aluno->notas[i][j]; 
        }
    }
    aluno -> mediaGeral = soma/(BIMESTRES * PROVAS);
}

void