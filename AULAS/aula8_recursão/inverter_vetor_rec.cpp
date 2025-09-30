#include <iostream>

using namespace std;

// =======================
// Função para trocar dois elementos do vetor
// =======================
void swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// =======================
// Função recursiva auxiliar para inverter o vetor
// =======================
void inverterAux(int *arr, int tamanho, int pos) {
    // Caso base: chegamos na metade do vetor, não há mais elementos para trocar
    if (pos >= tamanho / 2) return;

    // Troca o elemento da posição "pos" com seu espelho do outro lado
    swap(arr, pos, tamanho - 1 - pos);

    // Chamada recursiva para a próxima posição
    inverterAux(arr, tamanho, pos + 1);
}

// =======================
// Função principal para inverter o vetor
// =======================
void inverter(int *arr, int tamanho) {
    inverterAux(arr, tamanho, 0); // começa a recursão a partir da posição 0
}

// =======================
// Função principal
// =======================
int main() {
    int vetor[] = {0, 1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor original:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    inverter(vetor, tamanho); // Inverte o vetor

    cout << "Vetor invertido:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
