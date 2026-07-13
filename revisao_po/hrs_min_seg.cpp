#include <iostream>
using namespace std;
#include <string>

/*
int main(){
    string nomeTarefa1;
    int h1, m1, s1;
    char divisor;

    string nomeTarefa2;
    int h2, m2, s2;

    cin >> nomeTarefa1 >> h1 >> divisor >> m1 >> divisor >> s1;

    cin >> nomeTarefa2 >> h2 >> divisor >> m2 >> divisor >> s2;

    int totalSegundos1 = (h1*3600) + (m1*60) + s1;
    int totalSegundos2 = (h2*3600) + (m2*60) + s2;

    if(totalSegundos1 <= totalSegundos2){
        cout << 1 << endl;
    } else{
        cout << 2 << endl;
    }

    return 0;
}
*/

struct Tarefa {
    string nome;
    int hora;
    int minuto;
    int segundo;
};

int main (){
    Tarefa t1;
    Tarefa t2;
    char divisor;

    cin >> t1.nome >> t1.hora >> divisor >> t1.minuto >> divisor >> t1.segundo;
    cin >> t2.nome >> t2.hora >> divisor >> t2.minuto >> divisor >> t2.segundo;

    int totalSegundos1 = (t1.hora*3600) + (t1.minuto*60) + t1.segundo;
    int totalSegundos2 = (t2.hora*3600) + (t2.minuto*60) + t2.segundo;

    if(totalSegundos1 <= totalSegundos2){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}
