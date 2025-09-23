#ifndef _LISTADE
#define _LISTADE

#include "ListTAD.h"
#include "Node.h"

// =============================
// Lista Duplamente Encadeada
// =============================

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
    int  indexOf(int element);          //done
    void clear();                       //done
    std::string toString();             //done
};

#endif
