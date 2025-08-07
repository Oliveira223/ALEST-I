#include <iostream>
#include <fstream>

using namespace std;

class function{
    public: 
    int f1(int n);
    int f2(int n);
    int f3(int n);
    int f4(int n);
    int f5(int n);
    int f6(int n);
};



int main(){

    //time  ./progrma   #executa mostrando o tempo

    function f;
    ofstream arquivo("saida.csv");

    //F1
    for(int n = 1; n < 1000; n++){
        arquivo << f.f1(n) << "; ";
    }
    arquivo << endl;

    //F2
    for(int n = 1; n < 1000; n++){
        arquivo << f.f2(n) << "; ";
    }
    arquivo << endl;

    //F3
    for(int n = 1; n < 1000; n++){
        arquivo << f.f3(n) << "; ";
    }
    arquivo << endl;

    //F4
    for(int n = 1; n < 1000; n++){
        arquivo << f.f4(n) << "; ";
    }
    arquivo << endl;

    //F5
    for(int n = 1; n < 1000; n++){
        arquivo << f.f5(n) << "; ";
    }
    arquivo << endl;

    //F6
        //30  -> 4 
        //32  -> 18s
        //+32 -> ?
    for(int n = 1; n < 10; n++){
        arquivo << f.f6(n) << "; ";
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
        for(int j = i + 1; j < n; j++){
            r += 2;
        }
    }
    return r;
}


int function::f3(int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            r += 1;
        }
    }
    return r;
}

int function::f4(int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j < 2*i; j++){
           for(int k = i; k < j; k++){
               r += 1;    
           }
        }
    }
    return r;
}


int function::f5(int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j < i + 3; j++){
            for(int k = i; k < j; k++){
            r += 1;
            }
        }
    }
    return r;
}

int function::f6(int n){
    if(n == 0) {
        return 1;
    }
    else 
        return f6(n-1) + f6(n - 1);
     
}
