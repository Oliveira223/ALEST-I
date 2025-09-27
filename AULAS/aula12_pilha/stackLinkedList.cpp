#include <iostream>
#include <sstream>

#include "stackLinkedList.h"

using namespace std;

    // StackLinkedList();
    // void print();
    // void push(int e) = 0;  //empilha 
    // int pop() = 0;         //desempilha
    // int top() = 0;         //retorna o topo
    // void clear() = 0; 
    // bool isEmpty() = 0;    
    // int size() = 0;

StackLinkedList::StackLinkedList()
{
    lista = new ListSingleLinked();
}

/**
 * Imprime
 */
void StackLinkedList::printStack(){
    lista->print();
}

/**
 * Adiciona um elemento ao topo da pilha.
 * 
 * @param element elemento a ser adicionado ao topo da pilha
 */
void StackLinkedList::push(int element)
{
    lista->add(element);
}

/**
 * Remove um elemento ao topo da pilha.
 * 
 * @param element elemento a ser removido do topo da pilha
 */

int StackLinkedList::pop()
{
    if (lista->isEmpty()) {
        return -1;  // Valor indicativo de pilha vazia
    }
    return lista->removeByIndex(lista->size() - 1);
}
 
/**
 * Devolve o elemento do topo da pilha.
 * 
 * @param element elemento a ser devolvido do topo da pilha
 */
int StackLinkedList::top()
{
    if (lista->isEmpty()) {
        return -1;  // Valor indicativo de pilha vazia
    }
    return lista->get(lista->size() - 1);
}



/**
 * Limpa a pilha.
 */
void StackLinkedList::clear()
{
    if (lista->isEmpty()) {
        return;  // Valor indicativo de pilha vazia
    }

    for(int i = 0; i < lista->size(); i++){
        lista->removeByIndex(i);
    }
}


/**
 * Verifica se está vazia
 */
bool StackLinkedList::isEmpty()
{
    return lista->isEmpty();
}



/**
 * Devolve o tamanho.
 */
int StackLinkedList::size()
{
    return lista->size();
}