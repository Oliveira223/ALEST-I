#include <iostream>

using namespace std;


int busca_binaria(int a[], int ini, int fim, int busca){

    cout << "Vetor [ " << a[ini];
    for(int i = ini+1; i <= fim; i++){
        cout << ", " << a[i];
    }
    cout << " ]" << endl;

    if (ini > fim) return -1;           //não encontrou

    int meio = ini + (fim - ini) / 2;   //define o meio (mesmo quando não começa em 0)

    //Encontrou
    if(a[meio] == busca) return meio;  
    
    //Está na direita
    else if(a[meio] < busca){
        return busca_binaria(a, meio + 1, fim, busca);
    }

    //Está na esquerda
    else{
        return busca_binaria(a, ini, meio - 1, busca);
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

    cout << endl << "===========================================================" << endl << " > Vetor Inicial = [ " << vet[0];
    for(int i = 1; i < tam; i++){
        cout << ", " << vet[i];
    }
    cout << " ] " << endl << " > \"q\" to quit." << endl << "===========================================================" << endl;

    int busca;
    int q;

    while(true){
    cout << "Digite a busca: " << endl << " > ";
    cin >> busca;

   // Se falhou na leitura, pode ser que seja 'q'
        if (cin.fail()) {
            cin.clear(); // limpa o estado de erro
            char ch;
            cin >> ch; // lê o caractere que causou o erro
            if (ch == 'q') {
                cout << "Encerrando programa..." << endl;
                break;
            }
            else {
                cout << "Entrada inválida, tente novamente." << endl;
                cin.ignore(1000, '\n'); // descarta o resto da linha
                continue;
            }
        }

    //busca_linear(vet, tam, busca);

    int pos = busca_binaria(vet, 0, tam - 1, busca);
    if(pos == -1){
        cout << "Não encontrado." << endl;
    }
    else{
        cout << "Valor \"" << busca << "\" encontrado na posição " << pos << endl << endl;
    }
}

    return 0;
}
