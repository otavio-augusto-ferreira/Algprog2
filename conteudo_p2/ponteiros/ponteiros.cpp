#include <iostream>
using namespace std;

void troca(int* a, int* b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << "Antes da troca : x = " << x << " e y = " << y << endl;
    troca(&x, &y);
    cout << "Depois da troca : x = " << x << " e y = " << y << endl;
    return 0;
}