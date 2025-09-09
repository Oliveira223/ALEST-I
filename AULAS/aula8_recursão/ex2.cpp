// =======================
// Inverter Vetor
// =======================

#include <iostream>

using namespace std;

void swap(int* arr, int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void inverterAux(int *arr, int tamanho, int tamanhoDiv, int pos){
    if(pos < tamanhoDiv) return;
    swap(arr, pos, tamanho - 1 );
    inverterAux(arr, tamanho, tamanhoDiv, pos-1);
}

void inverter(int *arr, int tamanho){
    inverterAux(arr, tamanho, tamanho/2, 0);
}

int main(){
    int vetor[] = {0, 1, 2, 3, 4, 5};
    
    for(int i = 0; i < 6; i++){
        cout << vetor[i] << endl;
    }

    inverter(vetor, 6);

    for(int i = 0; i < 6; i++){
        cout << vetor[i] << endl;
    }
}
