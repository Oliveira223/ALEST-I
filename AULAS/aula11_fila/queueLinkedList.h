#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <string>
#include "QueueTAD.h"

using namespace std;

#define TAM_PADRAO 10

// ******************************************
//  Classe QueueArray
// ******************************************

class QueueLinkedList : public QueueTAD
{
private:
    int *data;
    int count;
    int tamVet;
    void setCapacity(int newCapacity);

public:
    QueueLinkedList();
    QueueLinkedList(int tam);
    void enqueue(int element);
    int head();
    int dequeue();
    string toString();
    void clear();
    bool isEmpty();
    int size();
};

#endif
