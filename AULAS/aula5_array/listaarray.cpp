#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#include "ListTAD.h" 

using namespace std;

#define TAM_PADRAO 10

// ******************************************
//  Classe ListArray
// ******************************************

class ListArray : public ListTAD {
    private:
        int *data;
        int count; //quantidade de itens (sempre no ultimo elemento)
        int tamVet;

    public:

        // Construtor
        ListArray();
        ListArray(int tam);

        void    print();                      //done
        void    clear();                      //done
        bool    isEmpty();                    //done
        int     size();                       //done
        void    add(int element);             //done
        void    add(int element, int pos);    //done
        int     get(int index);               //done
        bool    remove(int element);          //done
        int     indexOf(int element);         //done
        void    setCapacity(int newCapacity); //already done
        int     set(int index, int element);  //done
        bool    contains(int element);        //done
        int     capacity();
};

// Construtor
ListArray::ListArray() {
    tamVet = TAM_PADRAO;
    count = 0;
    data = new int[tamVet]; //data = (int*) malloc( sizeof(int) * tamVet );
}

// Construtor
ListArray::ListArray(int tam) {
    if (tam<=0)
        tamVet = TAM_PADRAO;
    else {
        tamVet = tam;
    }
    data = new int[tamVet]; // data = (int*) malloc( sizeof(int) * tamVet );
    count = 0;
}

// Imprimir Lista
void ListArray::print(){
    cout << "Lista = [ ";

    for(int i = 0; i < tamVet; i++){
    cout << setw(2) << data[i] <<  ", ";
    }

    cout << "\b\b ]" << endl;  //tira a ultima virgula
}

// Esvazia a lista.
void ListArray::clear(){
    tamVet = TAM_PADRAO;
    count = 0;
    delete[] data; // Libera os dados da lista antiga - free(data);
    data =  new int[tamVet](); // Aloca a lista nova - data = (int*) malloc( sizeof(int) * tamVet );
}

// Retorna true se a lista nao contem elementos, e false caso contrario. (considerando 0 = vazio?)
bool ListArray::isEmpty(){
    for(int i = 0; i < tamVet; i++){
        if(data[i] == 0){
            return true;
        }
    }
    return false;
}

// Retorna o numero de elementos armazenados na lista.
int ListArray::size(){
    return count;
}

// Adiciona um elemento ao final da lista.
void ListArray::add(int element) {
    if (count == tamVet)
        setCapacity(tamVet * 2);

    data[count] = element;
    count++;
}

void ListArray::add(int element, int pos){
    //antes do count
    if(pos < count){        
        for(int i = count; i > pos - 1; i--){ 
        data[i+1] = data[i];
        data[i] = data [i+1];
        }
        data[pos] = element;
        count++;
    }

    //no count (espaço vazio)
    else if(pos == count){
        data[count] = element;
        count++;
    }

    //Depois do count
    else {
        data[pos] = element;
    }
}

// Retorna o elemento de uma determinada posicao da lista.
int ListArray::get(int index) {
    if (index<0 || index>=count) {
        throw 0; // Erro (index < 0 ou maior/igual ao count)
    }
    return data[index];
}

// Redefine o tamanho da lista.
// Copia os dados da lista antiga para a lista nova.
// Caso a lista nova seja menor, os dados excedentes serao perdidos.
// Ao final do metodo, os dados da lista antiga sao liberados
void ListArray::setCapacity(int newCapacity) {
        if (newCapacity != tamVet) {
            int min = 0;
            int *newData = new int[newCapacity]; // int *newData = (int*) malloc( sizeof(int) * newCapacity );
            if (tamVet < newCapacity) {
                min = tamVet;
            } else {
                min = newCapacity;
            }
            for (int i = 0; i < min; i++) {
                newData[i] = data[i];
            }
            delete[] data; // Libera os dados da lista antiga - free(data);
            data = newData;
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


int ListArray::set(int index, int element) {
    int tmp = data[index];
    data[index] = element;

    return tmp;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */

// Consulta
bool ListArray::contains(int element) {
   for(int i = 0; i < tamVet; i++){
        if(data[i] == element) return true;
   }

   return false;
}

/**
 * Procura pelo elemento passado por parametro na lista, remove e retorna true se a
 * lista continha este elemento.
 * @param element o elemento a ser procurado
 * @return true se conseguir remover
 */
bool ListArray::remove(int element) {
    for(int i = 0; i < tamVet; i++){
        if(data[i] == element){
            data[i] = 0;
            return true;
        }
    }

    return false;
}

int ListArray::capacity() {
    return tamVet;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna sua posição,
 * se encontrar
 * @param element o elemento a ser procurado
 * @return posição se encontrado, -1 se não encontrado
 */
int ListArray::indexOf(int element) {
    for(int i = 0; i < tamVet; i++){
        if(data[i] == element) return i;
    }

    return -1;


}

// ******************************************
//  main
// ******************************************
int main()
{
    ListArray lista;
    int x = 0;

    lista.print();
    lista.add(2);
    lista.add(4);
    lista.add(6);
    lista.add(8);
    lista.add(10);
    lista.add(12);
    lista.add(14);

    lista.print();
    lista.add(7, 3);
    lista.print();
    lista.add(15, 8);
    lista.print();
    lista.add(17, 9);
    lista.print();
    cout << endl;

    cout << " > Tamanho da lista: "      << lista.size()      << endl << endl;
  
    cout << " > Elemento na posição 2: " << lista.get(2)      << endl << endl;

    cout << " > Tem o elemento 6? "      << lista.contains(6) << endl << endl;

    cout << " > Index de 6" << " = "     << lista.indexOf(6)  << endl << endl; 

    cout << "Removendo 6 da lista..."                      << endl;
    lista.print();
    if(lista.remove(6) == 1) {
        lista.print();
    } else{ 
        cout << "6 não está na lista.";
    }
    cout << endl;

    cout << "Trocando o primeiro elemento por 1: "  << endl;
    lista.print();
    cout << "Valor recebido: " << lista.set(0, 1) << endl;
    lista.print();

    cout << "\nLista limpa" << endl;
    lista.clear();
    lista.print();

    cout << "\nLista está vazia? " << lista.isEmpty() << endl;
        
//        cout << "Elemento armazenado na primeira posicao da lista: " << lista.get(0) << endl;
//        cout << "Elemento armazenado na ultima posicao da lista: " << lista.get(lista.size()-1) << endl;
}
