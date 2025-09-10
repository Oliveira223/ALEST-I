#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "ListDoubleLinked.h"

using namespace std;

// Construtor
ListDoubleLinked::ListDoubleLinked()
{
    // Inicializa sentinelas (precisa de elementos)
    this -> header  = new Node(0);
    this -> trailer = new Node(0);
    
    // Ponteiros Invalidos
    header  -> prev  = nullptr;
    trailer -> next  = nullptr;
    
    // Inicializar Ponteiros
    header -> next = trailer;
    trailer-> prev = header;
    
    this -> count = 0;
}

void ListDoubleLinked::print()
{
    cout << "\n[PRINT] ";

    if (count == 0) {
        cout << "A lista está vazia.\n";
        return;
    }

    Node* tmp = header->next; // começa no primeiro elemento real

    cout << "Header <-> ";
    while (tmp != trailer) {
        cout << "[" << tmp->element << "]";
        if (tmp->next != trailer) {
            cout << " <-> ";
        }
        tmp = tmp->next;
    }
    cout << " <-> Trailer\n";
}

/**
* Esvazia a lista.
*/
void ListDoubleLinked::clear()
{

}

/**
* Retorna true se a lista nao contem elementos.
* 
* @return true se a lista nao contem elementos
*/
bool ListDoubleLinked::isEmpty()
{
    return count == 0;
}

/**
* Retorna o numero de elementos armazenados na lista.
* 
* @return o numero de elementos da lista
*/
int ListDoubleLinked::size()
{
    return count;
}

/**
* Adiciona um elemento ao final da lista.
* 
* @param element elemento a ser adicionado ao final da lista
*/
void ListDoubleLinked::add(int element)
{
    cout << "[ADD] Adicionando \""<< element << "\" no inicio da lista." << endl;
    // Cria Nodo
    Node *novo = new Node(element);
    
    // Nodo temporario para não perder penultimo elemento
    Node *ant = trailer -> prev;

    // Trailer aponta para o Novo
    trailer -> prev = novo;

    // Novo aponta para o trailer pois é o último E para o anterior
    novo -> next = trailer;
    novo -> prev = ant;

    // Atualiza ponteiro do elemento anterior
    ant  -> next = novo;

    count++;
}

/**
* Adiciona um elemento antes de uma pos. específica
* 
* @param index   posição a inserir o novo elemento
* @param element elemento a ser adicionado
* 
*/
void ListDoubleLinked::add(int index, int element)
{
    if ((index < 0) || (index > count))
    {
        throw "Índice inválido";
    }
    
}

/**
* Retorna o elemento de uma determinada posicao da lista.
* 
* @param index a posicao da lista
* @return o elemento da posicao especificada
* @throws exception se (index < 0 || index >= size())
*/
int ListDoubleLinked::get(int index)
{
    if (index < 0 || index >= count)
    {
        throw "Índice inválido";
    }
    

    return 0;
}

/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo
 * elemento passado por parametro, retornando o elemento que foi substituido.
 * @param index a posicao da lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws exception se (index < 0 || index >= size())
 */
int ListDoubleLinked::set(int index, int element)
{
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }
 
    return 0;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListDoubleLinked::contains(int element)
{
    return indexOf(element) != -1;
}

/**
 * Procura pelo elemento passado por parametro na lista, remove e retorna true se a
 * lista continha este elemento.
 * @param element o elemento a ser procurado
 * @return true se conseguir remover
 */
bool ListDoubleLinked::remove(int element)
{

    return false;
}

/**
 * Remove um elemento da lista pela sua posição
 * lista continha este elemento.
 * @param index a posição do elemento
 * @return o elemento que estava na posição
 */
int ListDoubleLinked::removeByIndex(int index)
{
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }

    return 0;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna sua posição,
 * se encontrar
 * @param element o elemento a ser procurado
 * @return posição se encontrado, -1 se não encontrado
 */
int ListDoubleLinked::indexOf(int element)
{
    

    return 0;
}

/**
* Retorna o conteúdo da lista como uma string
* 
* @return uma string com os elementos da lista
*/
string ListDoubleLinked::toString()
{
    return 0;
}
