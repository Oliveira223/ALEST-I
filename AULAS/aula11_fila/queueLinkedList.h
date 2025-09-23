#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <string>
#include "QueueTAD.h"
#include "../aula6_linked/ListSingleLinked.h"

using namespace std;

#define TAM_PADRAO 10

// ******************************************
//  Classe QueueArray
// ******************************************

class QueueLinkedList : public QueueTAD
{
private:
    ListSingleLinked* lista;

public:
    QueueLinkedList();
    void enqueue(int element);
    int head();
    int dequeue();
    string toString();
    void clear();
    bool isEmpty();
    int size();
    void printQueue();
};

#endif
