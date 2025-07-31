#include <iostream>
#include <chrono>

using namespace std;

int main(){
    auto ini = chrono::system_clock::now();    
    int a[] = {1, 2, 3, 4, 5};
    int tam = sizeof(a) / sizeof(a[0]);

    for (int i=0; i<tam; i++){
        cout << "i = " << i << endl;
//        cout << "v = " << a[i] << endl;
    }
    
    auto fim = chrono::system_clock::now();

    chrono::duration<double>time = fim-ini; 

    cout << "Tempo: " << time.count();

    return 0;
}