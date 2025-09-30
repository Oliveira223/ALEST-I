#include <iostream>
#include <chrono>

using namespace std;

int bubble(int *array, int tam){
    int tmp;

    // ====== PRINT INICIAL =============
        cout << "Array: [";
        for(int p = 0; p < tam; p++){cout << array[p] << ", ";}
        cout << "\b\b]" << endl;
    // ===========================
    
    for(int i = 0; i < tam - 1; i++){  
        for (int j = 0; j < tam - 1 - i; j++){
            if(array[j] > array[j+1]){
                tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
        // ====== PRINT =============
        cout << "Array: [";
        for(int p = 0; p < tam; p++){cout << array[p] << ", ";}
        cout << "\b\b]" << endl;
        // ===========================
    }
    return 0;
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);

    // Tempo antes
    auto start = chrono::high_resolution_clock::now();
    bubble(a, tam);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;

    return 0;
}