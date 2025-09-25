#include <iostream>
#include "stackLinkedList.h"


using namespace std;

// ******************************************
//  Programa principal
// ******************************************
int main()
{
    // Cria uma pilha
    StackLinkedList pilha;

    pilha.print();

    // Insere alguns números
    pilha.push(2);  pilha.push(4);
    pilha.push(6);  pilha.push(8);
    pilha.push(10);

    // Remove e vai mostrando na tela até ficar vazia
    while (!pilha.isEmpty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
}
