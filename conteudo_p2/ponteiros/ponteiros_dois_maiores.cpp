#include <iostream> 
using namespace std; // importantndo a biblioteca 
#define MAX 100 // definindo tamanho máximo para o vetor

void dois_maiores(int n, int v[MAX], int* pr, int* seg){ //passando o parãmetros para a funcão
    /*pr e seg são ponteiros que são referenciados (&) na main*/
    if(v[0] > v[1]){         // verificamos se as posições 0 e 1 
        *pr = v[0];         // estão ordenadas crescentemente
        *seg = v[1];
    } else {
        *pr = v[1]; 
        *seg = v[0];
    }
    
    for(int i = 2; i < n; i++){  // inicializamos o contador a partir da posição 2
        if(v[i] > *pr){  // o if verifica se tal i do vetor é > que o elemento do ponteiro *pr
            *seg = *pr; // se for maior, logo encontrou-se o valor máximo do vetor e o ponteiro de *seg passa a apontar para o *pr 
            *pr = v[i]; // e *pr recebe o máximo valor "v[i]" encontrado
        } else if(v[i] > *seg){ // se v[i] não for maior que *pr, então verificamos se é > que *seg
            *seg = v[i]; // O valor apontado por *seg recebe o valor que estava em *pr
    }
}

int main() {
    int v[MAX], n;
    int pr_m, seg_m; // primeiro maior e segundo maior
    cout << "Informe o tamanho do vetor: " << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    dois_maiores(n, v, &pr_m, &seg_m);
    cout << "O primeiro maior valor eh: " << pr_m << endl;
    cout << "O segundo maior valor eh: "<< seg_m << endl;

    return 0;
}