#include <iostream>
#include <sstream>

#include "queueLinkedList.h"

using namespace std;

    // virtual void enqueue(int e) = 0;
    // virtual int dequeue() = 0;
    // virtual int head() = 0;
    // virtual void clear() = 0;
    // virtual bool isEmpty() = 0;
    // virtual int size() = 0;


QueueLinkedList::QueueLinkedList()
{
    lista = new ListSingleLinked();
}


/**
 * Adiciona um elemento ao final da fila.
 * 
 * @param element elemento a ser adicionado ao final da fila
 */
void QueueLinkedList::enqueue(int element)
{
    lista->add(element);
}

/**
 * Remove e retorna o primeiro da fila
 * @return primeiro da fila
 */
int QueueLinkedList::dequeue()
{
    return lista->removeByIndex(0);
}

int QueueLinkedList::head()
{
    return lista->get(0);
}

/**
* Esvazia a fila.
*/
void QueueLinkedList::clear()
{
   lista->clear();
}

/**
* Retorna true se a fila nao contem elementos.
* 
* @return true se a fila nao contem elementos
*/
bool QueueLinkedList::isEmpty()
{
    return lista->isEmpty();
}

/**
* Retorna o numero de elementos armazenados na fila.
* 
* @return o numero de elementos da fila
*/
int QueueLinkedList::size()
{
    return lista->size();
}

std::string QueueLinkedList::toString()
{
    std::ostringstream oss;
    for (int i = 0; i < lista->size(); ++i) {
        oss << lista->get(i);
        if (i < lista->size() - 1) oss << " ";
    }
    return oss.str();
}

void QueueLinkedList::printQueue()
{
    lista->print();
}

