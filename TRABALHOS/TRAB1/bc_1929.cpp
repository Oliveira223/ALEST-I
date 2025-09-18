// Ana e suas amigas estão fazendo um trabalho de geometria para o colégio, em que precisam formar vários triângulos, numa cartolina, com algumas varetas de comprimentos diferentes. Logo elas perceberam que não dá para formar triângulos com três varetas de comprimentos quaisquer: se uma das varetas for muito grande em relação às outras duas, não dá para formar o triângulo.

// Neste problema, você precisa ajudar Ana e suas amigas a determinar se, dados os comprimentos de quatro varetas, é ou não é possível selecionar três varetas, dentre as quatro, e formar um triângulo.

// Entrada
// A entrada é composta por apenas uma linha contendo quatro números inteiros A, B, C e D (1 ≤ A, B, C, D ≤ 100).

// Saída
// Seu programa deve produzir apenas uma linha contendo apenas um caractere, que deve ser ‘S’ caso seja possível formar o triângulo, ou ‘N’ caso não seja possível formar o triângulo.

#include <iostream>

using namespace std;

int main(){
    int lados[4];
    for(int i = 0; i < 4; i++){
        cin >> lados[i];
    }

    // Testar todas as combinações possíveis de 3 lados;
    bool valido = false;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 4; k++){
                // Aqui verifca todas as possibilidades
                int a = lados[i], b = lados[j], c = lados[k];
                // Se for triangulo valido (soma de 2 lados sempre maior que o terceiro)
                if(a + b > c && a + c > b && b + c > a){
                    valido = true;
                    break;
                }
            }
        }
    }
    
    if(valido) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}