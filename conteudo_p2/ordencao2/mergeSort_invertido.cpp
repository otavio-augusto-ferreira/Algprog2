#include <iostream>
using namespace std;
#define MAX 100

void merge(int p, int q, int r, int v[MAX]){
    int i, j, k;
    int w[MAX];
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r){
        if(v[i] >= v[j]){
            w[k] = v[i];
            i++;
        } else{
            w[k] = v[j];
            j++;
        }
        k++;
    }
    
    while (i < q){
        w[k] = v[i];
        i++;
        k++;
    }

    while(j < r){
        w[k] = v[j];
        j++;
        k++;
    }

    for (int i = p; i < r; i++){
        v[i] = w[i-p];
    }
}

void mergeSort(int p, int r, int v[MAX]){
    int q;
    if(p < r-1){
        q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        merge(p, q, r, v);
    }
}

int main(){
    int v[MAX] = {3, 41, 52, 26, 38, 57, 9, 49};
    int n = 8;

    cout << "Vetor original" << endl;
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    mergeSort(0, n, v);
    cout << "Vetor em ordem decrescente" << endl;
    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }


    return 0;
}