#include <iostream>
#include "Node.h"

using namespace std;

// Nodo duplamente encadeado
Node::Node(int i) {
    this->element = i;
    this->prev = NULL;
    this->next = NULL;
}

