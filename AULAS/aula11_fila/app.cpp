#include <iostream>
#include "queueLinkedList.h"


using namespace std;

// ******************************************
//  Programa principal
// ******************************************
int main()
{
    // Cria uma fila
    // QueueTAD fila = new QueueArray();
    QueueLinkedList fila;
    
    // Insere alguns números
    fila.printQueue();
    fila.enqueue(2);  fila.enqueue(4);
    fila.enqueue(6);  fila.enqueue(8);
    fila.enqueue(10); fila.printQueue();

    // Remove e vai mostrando na tela até ficar vazia
    while (!fila.isEmpty())
    {
        fila.printQueue();
        cout << fila.dequeue() << endl;
    }
}
