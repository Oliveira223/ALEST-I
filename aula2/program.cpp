#include <iostream>
#include <fstream>

using namespace std;

class function{
    public: 
    int f1(int n);
    int f2(int n);
    // int f3(int n);
    // int f4(int n);
    // int f5(int n);
};



int main(){

    function f;
    ofstream arquivo("saida.csv");

    for(int n = 1; n < 1000; n++){
        arquivo << f.f1(n) << "; ";
    }

    arquivo << endl;

    for(int n = 1; n < 1000; n++){
        arquivo << f.f2(n) << "; ";
    }

    arquivo << endl;

    arquivo.close();

    return 0;
}

int function::f1(int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        r += 1;
    }

    return r;
}

int function::f2(int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            r += 1;
        }
    }
    return r;
}

