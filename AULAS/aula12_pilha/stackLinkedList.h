#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <string>
#include "StackTAD.h"
#include "../aula6_linked/ListSingleLinked.h"

using namespace std;

#define TAM_PADRAO 10

// ******************************************
//  Classe QueueArray
// ******************************************

class StackLinkedList : public StackTAD
{
private:
    ListSingleLinked* lista;

public:
    StackLinkedList();
    void printStack();
    void push(int e);
    int pop();
    int top();
    void clear();
    bool isEmpty();
    int size();
};

#endif
