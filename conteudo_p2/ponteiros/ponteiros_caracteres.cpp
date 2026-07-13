#include <iostream>
using namespace std;
#define MAX 100

bool VerificaCaracteres(const char* texto, const char* sub){
    if (*sub == '\0'){
        return true;
    }
    const char* pTexto = texto;
    while(*pTexto != '\0'){
        if(*pTexto == *sub){
            const char* avancoTexto = pTexto;
            const char* avancoSub = sub;

            while (*avancoTexto != '\0' && *avancoSub != '\0' && *avancoTexto == *avancoSub){
                avancoTexto++;
                avancoSub++;
            }

            if (*avancoSub == '\0'){
                return true;
            }
        }
        pTexto++;
    }
    return false;
}

int main(){
    char textoP[MAX];
    char busca[MAX];
    cout << "Digite o texto principal: ";
    cin.getline(textoP, MAX);
    cout << "Digite a palavra que deseja buscar: ";
    cin.getline(busca, MAX);



    if(VerificaCaracteres(textoP, busca)){
        cout << "Sucesso! A substrig foi encontrada." << endl;
    } else {
        cout << "A substring nao existe no texto." << endl;
    }
    return 0;
}
