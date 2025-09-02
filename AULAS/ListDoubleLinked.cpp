#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "ListDoubleLinked.h"

using namespace std;

// Construtor
ListDoubleLinked::ListDoubleLinked()
{
    clear();
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
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna sua posição,
 * se encontrar
 * @param element o elemento a ser procurado
 * @return posição se encontrado, -1 se não encontrado
 */
int ListDoubleLinked::indexOf(int element)
{
    
}

/**
* Retorna o conteúdo da lista como uma string
* 
* @return uma string com os elementos da lista
*/
string ListDoubleLinked::toString()
{
    
}
