#include <iostream>

using namespace std;


void busca_binaria(int a[], int t, int b){
    int left = t/2;
    int right = t;
    if(left > b){
        //esta na esquerda
    }
    else {
        //esta na direita
    }


}


void busca_linear(int a[], int t, int b){
    bool flag = false;
    for(int i = 0; i < t; i++){
        if(b == a[i]){
          cout << "Posição: " << i << " do vetor" << endl;
          flag = true;
        }
    }

    if (!flag){
        cout << "Não encontrado!" << endl;
    }
}

int main(){
    int vet[10] = {0,2,4,6,8,10,12,14,16,18};
    int tam = sizeof(vet) / sizeof(vet[0]);

    int busca;

    cout << "Digite a busca: " << endl;
    cin >> busca;


    busca_linear(vet, tam, busca);
    
    return 0;
}
