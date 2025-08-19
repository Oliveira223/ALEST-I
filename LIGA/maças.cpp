#include <iostream>

using namespace std;

int main(){
    int maças = 86134;
    int contagem = 0;
    for(int i = 0; i < maças; i++){
        if((i % 2) == 1){ //se impar
            contagem++;
        }
    }

    cout << contagem;
}