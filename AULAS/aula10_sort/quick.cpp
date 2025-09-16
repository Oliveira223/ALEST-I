#include <iostream>

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
    for(int i = 0; i < tam - 1; i++){        
        // ====== PRINT =============
        cout << "Array: [";
        for(int i = 0; i < tam; i++){cout << a[i] << ", ";}
        cout << "\b\b] " << "Pivo = " << a[pivo] << " Div = "  << a[div]  << endl; 
        // ===========================
   
        if(a[i] < a[pivo]){
            // Swap(i, div)
            int tmp = a[div];
            a[div] = a[i];
            a[i] = tmp;
            div++;
        }
    }
    
    int tmp = a[div];
    a[div] = a[pivo];
    a[pivo] = tmp;
    return 0;
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);
    // print(a, tam);
    quick(a, tam);
    // print(a, tam);
 
    return 0;
}