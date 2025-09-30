#include <iostream>
#include <chrono>

using namespace std;

void print(int *a, int tam){
     // ====== PRINT =============
    cout << "Array: [";
    for(int i = 0; i < tam; i++){cout << a[i] << ", ";}
    cout << "\b\b]" << endl;
    // ===========================

}

// Usa um pivo como base
// Div avança do inicio ao final
int quick(int *a, int tam){
    int pivo = tam - 1;
    int div  = 0; 

    // Caso base, se o tamanho do array for menor que 2 retorna pois ja esta ordenado
    if(tam < 2){
    cout <<" > Base" << endl;
    return 0;
    }
    for(int i = 0; i < tam - 1; i++){        
        // ====== PRINT =============
        cout << "Array: [";
        for(int j = 0; j < tam; j++){cout << a[j] << ", ";}
        cout << "\b\b] " << "PivoPos = " << pivo << " DivPos = "  << div << endl; 
        // ===========================
   
        // Se o pivo for maior que a[i], 
        if(a[i] < a[pivo]){
            // Swap(i, div)
            int tmp = a[div];
            a[div] = a[i];
            a[i] = tmp;
            div++;
        }
    }
    
    // Swap(div, pivo) para colocar o pivo na posicao correta
    int tmp = a[div];
    a[div] = a[pivo];
    a[pivo] = tmp;

    // Quick sort na esquerda do pivo
    cout << "Chamando esquerda" << endl;;
    
    // Passa a array do inicio até o meio
    quick(a, div);

    // Quick sort na direita do pivo
    cout << "Chamando direita" << endl;

    // Passa a array começando pelo meio e indo até o final
    quick(a + div + 1, tam - div - 1);
    
    return 0;
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);
    cout << "Inicio ===============" << endl;
    print(a, tam);
    cout << "======================" << endl << endl;

    auto start = chrono::high_resolution_clock::now();
    quick(a, tam);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << endl;
    
    cout << "Fim ==================" << endl;
    print(a, tam);
    cout << "======================" << endl;
    cout << "> Tempo de execução: " << duration.count() << " ms" << endl;
 
    return 0;
}