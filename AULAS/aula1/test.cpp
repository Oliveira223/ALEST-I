#include <iostream>
#include <chrono>

using namespace std;

int main(){

    int inter = 0;

    //=====================================================
    //Complexidade N 
    //====================================================
    cout << "Complexidade n" << endl;
    auto ini2 = chrono::high_resolution_clock::now();    
    int a2[2] = {};
    int tam2 = sizeof(a2) / sizeof(a2[0]);

    for (int i=0; i<tam2; i++){
        inter++;
        cout << "Interações = " << inter << endl;
    }
    
    //Conta tempo
    auto fim2 = chrono::high_resolution_clock::now();

    // Calcula a diferença de tempo
    auto duration2 = chrono::duration_cast<chrono::microseconds>(fim2 - ini2);

    // Exibe o tempo decorrido em microssegundos
    cout << "Tempo de execução: " << duration2.count() << " microssegundos \n" << std::endl;


    //=====================================================
    //Complexidade N² 
    //====================================================
    cout << "Complexidade N²" << endl;
    auto ini = chrono::high_resolution_clock::now();    
    int a[3] = {};
    int tam = sizeof(a) / sizeof(a[0]);

    inter = 0;

    for (int i = 0; i < tam; i++){
        inter++;
        cout << "Interações = " << inter << endl;
            for(int j = 0; j < tam; j++){
            inter++;
            cout << "Interações = " << inter << endl;
            }
    }
    
    //Conta tempo
    auto fim = chrono::high_resolution_clock::now();

    // Calcula a diferença de tempo
    auto duration = chrono::duration_cast<chrono::microseconds>(fim - ini);

    // Exibe o tempo decorrido em microssegundos
    cout << "Tempo de execução: " << duration.count() << " microssegundos\n " << std::endl;




    return 0;
}