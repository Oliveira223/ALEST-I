#include <iostream>

using namespace std;

int binaria_rec(int *array, int procurado, int inicio, int fim){
    int meio = (inicio+fim)/2;

    if(inicio > fim) return -1;

    // Se estiver no meio
    if(procurado == array[meio]) return meio;

    // Antes do meio
    if(procurado < array[meio]){
        cout << "Encontrado" << endl;
        return binaria_rec(array, procurado, inicio, meio);
    }

    // Depois do Meio
    else{
        cout << "Encontrado" << endl;    
        return binaria_rec(array, procurado, meio+1, fim); 
    }
}



int main(){
    int a[] = {0, 1, 2, 3, 4, 5,};
    int b[] = {1, 2, 3, 4, 5};
    //int tam = sizeof(a) / sizeof(a[0]);
    //cout << tam;

    cout <<  binaria_rec(a, 4, 0, 5);






    return 0;
}