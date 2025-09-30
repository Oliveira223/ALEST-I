#include <iostream>
#include <chrono>

using namespace std;

// Busca binária recursiva
int busca_binaria(int a[], int ini, int fim, int busca) {
    if (ini > fim) return -1;  // não encontrou

    int meio = ini + (fim - ini) / 2;

    if (a[meio] == busca) return meio;           // encontrado
    else if (a[meio] < busca)                    // está na direita
        return busca_binaria(a, meio + 1, fim, busca);
    else                                         // está na esquerda
        return busca_binaria(a, ini, meio - 1, busca);
}

// Busca linear simples
int busca_linear(int a[], int t, int b) {
    for (int i = 0; i < t; i++) {
        if (b == a[i]) return i; // retorna a posição da primeira ocorrência
    }
    return -1; // não encontrado
}

int main() {
    const int tam = 10000;
    int vet[tam];

    // Preenche vetor com números pares: 0, 2, 4, ...
    for (int i = 0; i < tam; i++) {
        vet[i] = i * 2;
    }

    cout << "Vetor inicial criado com " << tam << " elementos (0, 2, 4, ...)" << endl;
    cout << "Digite um número para buscar (ou 'q' para sair)." << endl;

    while (true) {
        cout << "Digite a busca: " << endl << " > ";
        int busca;
        cin >> busca;

        if (cin.fail()) {
            cin.clear();
            char ch;
            cin >> ch;
            if (ch == 'q') {
                cout << "Encerrando programa..." << endl;
                break;
            } else {
                cout << "Entrada inválida, tente novamente." << endl;
                cin.ignore(1000, '\n');
                continue;
            }
        }

        // Busca binária
        auto start = chrono::high_resolution_clock::now();
        int pos1 = busca_binaria(vet, 0, tam - 1, busca);
        auto end = chrono::high_resolution_clock::now();
        auto duration_bin = chrono::duration_cast<chrono::nanoseconds>(end - start);

        // Busca linear
        start = chrono::high_resolution_clock::now();
        int pos2 = busca_linear(vet, tam, busca);
        end = chrono::high_resolution_clock::now();
        auto duration_lin = chrono::duration_cast<chrono::nanoseconds>(end - start);

        // Resultados
        if (pos1 == -1) {
            cout << "Não encontrado." << endl;
        } else {
            cout << "Valor \"" << busca << "\" encontrado na posição " << pos1 << endl;
        }

        cout << "Tempo de execução (busca binária): " << duration_bin.count() << " ns" << endl;
        cout << "Tempo de execução (busca linear): " << duration_lin.count() << " ns" << endl;
        cout << endl;
    }

    return 0;
}
