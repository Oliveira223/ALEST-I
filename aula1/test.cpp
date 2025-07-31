#include <iostream>
#include <chrono>

using namespace std;

int main(){
    auto ini = chrono::system_clock::now();    
    int a[] = {1, 2, 3, 4, 5};
    int tam = sizeof(a) / sizeof(a[0]);

    for (int i=0; i<tam; i++){
       cout << "v = " << a[i] << endl;
    }
    
    //Conta tempo
    auto fim = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(fim - ini);
    cout << "Tempo: " << time.count();

    return 0;
}