#ifndef _LISTADE
#define _LISTADE

#include "ListTAD.h"
#include "Node.h"

// =============================
// Lista Duplamente Encadeada
// =============================

        // virtual void print() = 0;
        // virtual void add(int element) = 0;
        // virtual void add(int index, int element) = 0;
        // virtual int  get(int index) = 0;
        // virtual int  set(int index, int element) = 0;
        // virtual bool remove(int element) = 0;
        // virtual int  removeByIndex(int index) = 0;
        // virtual bool isEmpty() = 0;
        // virtual int  size() = 0;
        // virtual bool contains(int element) = 0;
        // virtual int  indexOf(int element) = 0;
        // virtual void clear() = 0;
        // virtual void addFirst(int e) = 0;
        // virtual int  getFirst() = 0;
        // virtual int  getLast() = 0;
        // virtual int  removeFirst() = 0;
        // virtual int  removeLast() = 0;


class ListDoubleLinked : public ListTAD { 

    // Referência para o sentinela de início
    Node *header;
    // Referência para o sentinela de fim
    Node *trailer;
    // Contador para a quantidade de elementos que a lista contém
    int count;
    
public:
    ListDoubleLinked();           
    void print();                       //done
    void add(int element);              //done
    void add(int index, int element);   //done
    int  get(int index);                //done
    int  set(int index, int element);   //done
    bool remove(int element);           //done
    int  removeByIndex(int index);      //done
    bool isEmpty();                     //done
    int  size();                        //done
    bool contains(int element);         //done
    int  indexOf(int element);          //done (testar)
    void clear();                       //done
    std::string toString();             //done
    void addFirst(int e);               
    int  getFirst();                    
    int  getLast();
    int  removeFirst();
    int  removeLast();
    
};

#endif
