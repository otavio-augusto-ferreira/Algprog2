#include <iostream>
#include <string>

using namespace std;
#define MAX 100

struct Pessoa{
    string nome;
    int idade;
}

void intercala(int p, int q, int r, Pessoa v[MAX]){
    Pessoa w[MAX];
    int i = p, j = q + 1, k = 0;

    while(i <= q && j <= r){
        if(v[i].idade < v[j].idade || (v[i].idade == v[j].idade && v[i].nome < v[j].nome)){
          w[k] = v[i];
          i++;  
        } else{
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= q){
        w[k] = v[i];
        i++;
        k++;
    }

    while (j <= r){
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p, k = 0; i <= r, i++, k++){
        v[i] = w[k];
    }
}

void mergeSort(int p, int r, Pessoa v[MAX]){
    if (p < r){
        int q = (p + r)/2;

        mergeSort(p, q, v);
        mergeSort(q + 1, r, v);

        intercala(p, q, r, v);
    }
}

int maib(){
    int n;
    Pessoa v[MAX];

    cout << "Informe o número de pessoas: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Nome da pessoa " << i + 1 << ": " ;
        cin >> v[i].nome;
        cout << "Idade da pessoa " << i + 1 << ": ";
        cin >> v[i].idade;
    }

    mergeSort(0, n - 1, v);

    cout << "\n --- LISTA ORDENADA ---" << endl;
    for (int i = 0; i < n; i++){
        cout << v[i].nome << " - " << v[i].idade << " anos " << endl;
    }
    return 0;
}