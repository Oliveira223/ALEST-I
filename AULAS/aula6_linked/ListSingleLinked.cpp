#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "ListSingleLinked.h"

using namespace std;

// Construtor
ListSingleLinked::ListSingleLinked()
{
    //Usa variaveis da classe; (não é necessário pois não recebe parametros, logo não tem ambiguidade)
    this ->  count = 0;
    this ->  head  = nullptr;
    this ->  tail  = nullptr;
}

/**
* Esvazia a lista.
*/
void ListSingleLinked::clear()
{
}

/**
* Retorna true se a lista nao contem elementos.
* 
* @return true se a lista nao contem elementos
*/
bool ListSingleLinked::isEmpty()
{
    return count == 0;
}

/**
* Retorna o numero de elementos armazenados na lista.
* 
* @return o numero de elementos da lista
*/
int ListSingleLinked::size()
{
    return count;
}

/**
* Adiciona um elemento ao final da lista.
* 
* @param element elemento a ser adicionado ao final da lista
*/
void ListSingleLinked::add(int element)
{
    Node* novo = new Node(element); // Cria Nodo

    // Se a lista estiver vazia
    if(count == 0){
        head = novo;
        tail = novo;
        count ++;
        return;
    }

    tail -> next = novo;    // O ptr Next do Tail aponta para o Novo
    tail = novo;            // Atualiza a posição do tail
    count++;                // Atualiza o numero de elementos
}

/**
* Adiciona um elemento antes de uma pos. específica
* 
* @param index   posição a inserir o novo elemento
* @param element elemento a ser adicionado
* 
*/
void ListSingleLinked::add(int index, int element)
{
    if ((index < 0) || (index > count))
    {
        throw "Índice inválido";
    }

    Node* novo = new Node(element);

    // Se a lista estiver vazia
    if(count == 0){
       add(element);
       return;
    }

    // Se quiser adicionar no inicio
    if(index == 0){
        novo -> next = head;
        head = novo;
        count++;
        return;
    }

    Node* atual = head;
    for(int i = 0; i < index - 1; i++){
        atual = atual -> next;     // Encontra a posição antes do index
    }

    novo  -> next = atual -> next; // Atualiza o ptr antigo para o novo
    atual -> next = novo;          // O novo aponta para o next (do antigo)
    count++;
}

/**
* Retorna o elemento de uma determinada posicao da lista.
* 
* @param index a posicao da lista
* @return o elemento da posicao especificada
* @throws exception se (index < 0 || index >= size())
*/
int ListSingleLinked::get(int index)
{
    if (index < 0 || index >= count)
    {
        throw "Índice inválido";
    }

    Node* atual = head;
    for(int i = 0; i < index; i++){
        atual = atual -> next;     // Encontra a posição do index
    }

    return atual->element;         // Retorna o valor "elemento" do Nodo selecionado
}

/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo
 * elemento passado por parametro, retornando o elemento que foi substituido.
 * @param index a posicao da lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws exception se (index < 0 || index >= size())
 */
int ListSingleLinked::set(int index, int element)
{
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }

    Node* atual = head;
    for(int i = 0; i < index; i++){
        atual = atual -> next;     // Encontra a posição do index
    }

    







}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListSingleLinked::contains(int element)
{
    return indexOf(element) != -1;
}

/**
 * Procura pelo elemento passado por parametro na lista, remove e retorna true se a
 * lista continha este elemento.
 * @param element o elemento a ser procurado
 * @return true se conseguir remover
 */
bool ListSingleLinked::remove(int element)
{
}

/**
 * Remove um elemento da lista pela sua posição
 * lista continha este elemento.
 * @param index a posição do elemento
 * @return o elemento que estava na posição
 */
int ListSingleLinked::removeByIndex(int index)
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
int ListSingleLinked::indexOf(int element)
{
}

string ListSingleLinked::toString()
{
    ostringstream aux;
    aux << "[ ";
    //for (int pos = 0; pos < count; pos++)
    //    aux << data[pos] << " ";
    aux << "]";
    return aux.str();
}

