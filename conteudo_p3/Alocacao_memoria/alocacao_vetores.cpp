 #include <iostream>
 using namespace std;
 #include <new>

 int main(){
    int tamanho;
    cout << "Digite o tamanho: ";
    cin >> tamanho;

    //criando um ponteiro que recebe novo vetor vazio
    int *vetor = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        vetor[i] = i;
        cout << vetor[i] << endl;
    }

    free(vetor);
    
    return 0; 
 }