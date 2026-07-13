#include <iostream>
#include <chrono> // medição do tempo 
using namespace std;
#define MAX 10000

void insertion_sort(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j;
        for(j = i - 1; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
}

void merge(int p, int q, int r, int v[MAX]){
    int i, j, k;
    int w[MAX];
    i = p;
    j = p;
    k = 0;

    while(i < q && j < r){
        if(v[i] <= v[j]){
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while(i < q){
        w[k] = v[i];
        i++;
        k++;
    }
    
    while (j < r){
        w[k] = v[j];
        j++;
        k++;
    }

    for(i = p; i < r; i++){
        v[i] = w[i-p];
    }
}

mergeSort(int p, int r, int v[MAX]){
    if (p < r-1){
        int q = (p+r)/ 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        merge(p, q, r, v);
    }
}

int main(){
    int v[MAX], n;
    cout << "Informe o tamanho do vetor: " << endl;
    cin >> n;
    // validação para evitar erro de memória
    if(n > MAX || n <= 0){
        cout << "Tamanho invalido!" << endl;
        return 1;
    }
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << "Insertion_sort" << endl;
    cout << "\nOrdenando e analisando eficiencia" << endl;
    auto inicio = chrono::high_resolution_clock::now();

    insertion_sort(v, n);
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> tempo_total = fim - inicio;

    cout << "Vetor ordenado: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    cout << "Tempo gasto: " <<tempo_total.count() << "ms" << endl;

    cout << "Merge sort" << endl;
    cout << "\nOrdenando e analisando eficiencia" << endl;
    auto inicio_m = chrono::high_resolution_clock::now();
    merge_sort(v, 0, n-1);
    auto fim_m = chrono::high_resolution_clock::now();
    

    return 0;
}