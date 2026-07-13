#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

void troca(int &n1, int &n2){
    int aux = n1;
    n1 = n2;
    n2 = aux;
}

void bubble_sort(int v[MAX], int n){
    for (int i = n-1; i > 0; i--)
        for(int j = 0; j < i; j++)
            if (v[j] > v[j+1])
                troca(v[j], v[j+1]);
}

void selection_sort(int v[MAX], int n){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        
        troca(v[i], v[min]);
    }
}

void insertion_sort(int v[MAX], int n){
    for(int i = 1; i < n; i++){
        int x = v[i];
        int j;
        for(j = i-1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];

        v[j+1] = x;


    }
}

