#include <iostream>
using namespace std;
#define MAX 100

bool verifica_ordem(int v[MAX], int n){
    for (int i = 0; i < n-1; i++){
        if (v[i] > v[i+1]) return false;
    }
    return true;
}

int main (){

    return 0;
}