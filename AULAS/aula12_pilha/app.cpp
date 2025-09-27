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

    pilha.printStack();

    // Insere alguns números
    pilha.push(2);  pilha.printStack();
    pilha.push(4);  pilha.printStack();
    pilha.push(6);  pilha.printStack();
    pilha.push(8);  pilha.printStack();
    pilha.push(10); pilha.printStack();

    // Remove e vai mostrando na tela até ficar vazia
    while (!pilha.isEmpty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
}
