#include <iostream>
using namespace std;
#define MAX 100

void insertion_sort(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j;
        for(j = i-1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];

        v[j+1] = x;
    }   
}

int busca(int v[MAX], int n, int x){
    int esq = -1;
    int dir = n;
    while(esq < dir-1){
        int meio = (esq+dir)/2;
        if(v[meio] == x)
            return meio;

        if(v[meio] < x)
            esq = meio + 1;
        else
            dir = meio - 1;    
    }
    return dir;
}

bool verifica(int v[MAX], int n, int x){
    for(int i = 0; i < n; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}


int main (){
    int v[MAX], n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x;
    if (verifica(v, n, x)){
        cout << x << " " << busca(v, n, x) << endl;
    } 
    else {
        insertion_sort(v, n);
        cout << x << " " << busca(v, n, x) << endl;
    }
    return 0;
}