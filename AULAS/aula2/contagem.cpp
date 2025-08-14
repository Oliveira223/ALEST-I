#include <iostream>

using namespace std;

int main(){

    int r = 0;
    int tam;
    
    cout << "Digite o tamanho: ";
    cin >> tam;
    cout << "Tamanho:" << tam << endl; 

    // N³
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            for (int k = 0; k < tam; k++){
                r += 1;
            }
        }
    }

    cout << "Interações = " << r << endl;
}