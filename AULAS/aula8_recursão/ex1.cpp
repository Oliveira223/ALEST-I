// =======================
// RECURSÃO
// =======================

#include <iostream>

using namespace std;

int pow(int base, int expoente){
    if(expoente > 0){
        int resultado = 1;
        for(int i = 0; i < expoente; i++){
            resultado *= base;        
        }
        return resultado;
    }

    return -1;
    //2^4 -> 16
    // 2 -> *2 -> *2 -> *2 -> *2
}

int pow_rec(int base, int expoente){
    if(expoente == 0){
        return 1;
    } else if(expoente > 0){
        return (base * pow_rec(base, expoente - 1)) ;
    } 

    return -1;
}




int main(){
    int base, exp  = 0;

    // cout << "[LOOP] Insira a Base e o Expoente: " << endl;
    // cin >> base >> exp;
    // cout << "Resultado: " << pow(base, exp) << endl;

    cout << "[REC] Insira a Base e o Expoente: " << endl;
    cin >> base >> exp;
    cout << "Resultado: " << pow_rec(base, exp) << endl;

    return 0;
}