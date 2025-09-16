#include <iostream>

using namespace std;

int insertion(int *a, int tam){
    int mov, div = 0;
    int chave;

    for (div = 1; div <= tam; div++){  // começa no index 2
        // ====== PRINT =============
        cout << "Array: [";
        for(int i = 0; i < tam; i++){cout << a[i] << ", ";}
        cout << "\b\b]" << endl;
        // ===========================
        
        chave = a[div]; 
        mov = div - 1;

        while( (chave < a[mov]) && (mov >= 0) ){
            //cout << "entrei";
            a[mov + 1] = a[mov];
            mov--;
        }
        a[mov + 1] = chave;
        
    }
    
    return 0;
}


int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);
    insertion(a, tam);
    
    return 0;
}