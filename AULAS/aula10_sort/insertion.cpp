#include <iostream>
#include <chrono>

using namespace std;

// Função de ordenação por Insertion Sort
// Recebe um array 'a' e seu tamanho 'tam'
void insertion(int *a, int tam) {
    int mov, div = 0; // 'div' é o índice do elemento a ser inserido
    int chave;        // 'chave' guarda o valor que será comparado e inserido

    // Percorre o array a partir do segundo elemento (índice 1),
    // pois o primeiro já pode ser considerado "ordenado"
    for (div = 1; div < tam; div++) {   
        
        chave = a[div];    // Pega o elemento atual (a ser inserido na parte ordenada)
        mov = div - 1;     // Começa a comparação pelo elemento imediatamente à esquerda
        
        // Enquanto 'mov' não for negativo e o elemento da esquerda for maior que a 'chave',
        // desloca o elemento uma posição para a direita para abrir espaço
        while (mov >= 0 && a[mov] > chave) {
            a[mov + 1] = a[mov]; // Desloca elemento para a direita
            mov--;               // Avança para a próxima posição à esquerda
        }

        // Quando o while termina, 'mov' está no índice anterior
        // à posição correta da 'chave'. Então inserimos a 'chave'
        // logo após esse índice (mov + 1).
        a[mov + 1] = chave;
        
        // ====== PRINT =============
        cout << "Array: [";
        for(int i = 0; i < tam; i++){cout << a[i] << ", ";}
        cout << "\b\b]" << endl;
        // ===========================
    }
    
}

int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);
    
    // Tempo antes
    auto start = chrono::high_resolution_clock::now();
    insertion(a, tam);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;

    return 0;
}