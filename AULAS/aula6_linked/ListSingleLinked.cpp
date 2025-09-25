#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "ListSingleLinked.h"

using namespace std;

// Construtor
ListSingleLinked::ListSingleLinked()
{
    // Usa variaveis da classe; (não é necessário pois não recebe parametros, logo não tem ambiguidade)
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void ListSingleLinked::print()
{

    cout << "\n[PRINT] ";
    if (head == nullptr)
    {
        cout << "A lista está vazia" << endl;
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < count; i++)
    {
        cout << "[ " << tmp->element << " ]-> ";
        tmp = tmp->next; // Encontra a posição do index
    }
    cout << "NULL\n"
         << endl;
}

/**
 * Esvazia a lista.
 */
void ListSingleLinked::clear()
{
    cout << "[CLEAR] Limpando lista..." << endl;
    Node *prev = head;
    Node* del;

    // Se lista vazia
    if(!head){
        cout << "[REM] Lista vazia." << endl;
    }

    while(prev->next){
        cout << "Entrei no while\n";
        del = prev->next;
        prev->next = prev->next->next; // atualiza ptr (prev->next->next)

        // Se for o tail
        if(del == tail)
            tail = prev;

        prev = prev->next; //vai para o prox elemento
       // print();
        count--;
        delete del;
    }
    cout<< "Sai do while\n";
    print();
    
    // Node *atual = head;
    // Node *prox;
    // for (int i = 0; i < count; i++)
    // {
    //     prox = atual->next;
    //     delete[] atual;
    //     atual = prox;
    // }
    // head = nullptr;
    // count = 0;
    // cout << "[CLEAR] Lista Limpa" << endl;
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
    Node *novo = new Node(element); // Cria Nodo

    // Se a lista estiver vazia
    if (count == 0)
    {
        head = novo;
        tail = novo;
        count++;
        return;
    }

    tail->next = novo; // O ptr Next do Tail aponta para o Novo
    tail = novo;       // Atualiza a posição do tail
    count++;           // Atualiza o numero de elementos
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
    cout << "[ADD1] Adicionando " << element << " no index " << index << endl;
    if ((index < 0) || (index > count))
    {
        throw "Índice inválido";
    }

    Node *novo = new Node(element);

    // Se a lista estiver vazia
    if (count == 0)
    {
        add(element);
        return;
    }

    // Se quiser adicionar no inicio
    if (index == 0)
    {
        novo->next = head;
        head = novo;
        count++;
        return;
    }

    Node *atual = head;
    for (int i = 0; i < index - 1; i++)
    {
        atual = atual->next; // Encontra a posição antes do index
    }

    novo->next = atual->next; // Atualiza o ptr antigo para o novo
    atual->next = novo;       // O novo aponta para o next (do antigo)
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
        cout << "[GET] Índice inválido";
        return -1;
    }

    cout << "[GET] Elemento no index " << index << ": ";

    Node *atual = head;
    for (int i = 0; i < index; i++)
    {
        atual = atual->next; // Encontra a posição do index
    }
    return atual->element; // Retorna o valor "elemento" do Nodo selecionado
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
        cout << "[SET] Índice inválido!";
        return -1;
    }

    cout << "[SET] Colocando valor " << element << " no index " << index << ". Valor devolvido: ";

    Node *atual = head;
    for (int i = 0; i < index; i++)
    {
        atual = atual->next; // Encontra a posição do index
    }
    int tmp = atual->element;
    atual->element = element;

    return tmp;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListSingleLinked::contains(int element)
{
    if(indexOf(element) > -1){
        cout << "[CONTAINS] A Lista contém o elemento " << element << endl;
        return true;
    } 

    cout << "[CONTAINS] A Lista não contém o elemento " << element << endl;
    return -1;
}

/**
 * Procura pelo elemento passado por parametro na lista, remove e retorna true se a
 * lista continha este elemento.
 * @param element o elemento a ser procurado
 * @return true se conseguir remover
 */
bool ListSingleLinked::remove(int element)
{   
    cout << "[REM] Procurando elemento: " << element << endl;
    Node *prev = head;
    Node* del;

    // Se lista vazia
    if(!head){
        cout << "[REM] Lista vazia." << endl;
        return false;
    }

    // Caso o elemento seja o head
    if (head->element == element) {
        del = head;
        head = head->next;
        if (!head) // lista ficou vazia
            tail = nullptr;
        delete del;
        count--;
        cout << "[REM] Elemento encontrado." << endl;
        return true;
    }

    // Enquanto (prev->next) não for nullptr
    while(prev->next)
    {
        // Se encontrar
        if(prev->next->element == element){
            del = prev->next;
            prev->next = del->next;

            // Se for o tail
            if(del == tail)
                tail = prev;

            cout << "[REM] Elemento encontrado."<< endl;
            count--;
            delete del;
            return true;
        }

        // Se não encontrar
        prev = prev->next;

    }
    cout << "[REM] Elemento não encotrado."<< endl;    
    return false;
}

/**
 * Remove um elemento da lista pela sua posição
 * lista continha este elemento.
 * @param index a posição do elemento
 * @return o elemento que estava na posição
 */
int ListSingleLinked::removeByIndex(int index)
{   cout << "[REM_IND] Removendo elemento do index: " << index << endl;
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }

    Node *del;
    int tmp;

    if (index == 0)
    {
        del = head; // Ponteiro para head
        tmp = del->element;
        head = head->next;

        // Se a lista ficar vazia (só um elemento)
        if (count == 1)
        {
            tail = nullptr;
        }
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev -> next; // Encontra a posição do index
        }
        del = prev->next;
        tmp = del->element;
        prev -> next = del->next;

        //Se del é o ultimo elemento, aponta para o anterior
        if(del == tail){
            tail = prev;
        }
    }

    cout << "[REM_IND] Elemento removido: ";
    count--;
    delete del;
    return tmp;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna sua posição,
 * se encontrar
 * @param element o elemento a ser procurado
 * @return posição se encontrado, -1 se não encontrado
 */
int ListSingleLinked::indexOf(int element)
{
    cout << "[IndexOF] Procurando Elemento: " << element << endl;
    int indexof = 0;
    Node *atual = head;
    for (int i = 0; i < count; i++)
    {
        if(atual->element == element){
            cout << "[IndexOf] Elemento Encontrado no index: " << indexof << endl;
            return true;
        }
        atual = atual->next; 
        indexof++;
    }

    cout << "[IndexOF] Elemento Não encontrado. " << endl;
    return -1;
}

string ListSingleLinked::toString()
{
    ostringstream aux;
    aux << "[ ";
    for (int i = 0; i < count; i++){
        aux << get(i);
        if (i < count - 1) aux << " ";
    }
    aux << " ]" << endl;
    return aux.str();
}
