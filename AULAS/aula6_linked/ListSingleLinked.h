#ifndef _LISTASE
#define _LISTASE

#include "ListTAD.h"
#include "Node.h"

// =============================
// Lista Simplesmente Encadeada
// ============================

class ListSingleLinked : public ListTAD { 

    // Referência para o primeiro elemento da lista encadeada
    Node *head;
    // Referência para o último elemento da lista encadeada
    Node *tail;
    // Contador para a quantidade de elementos que a lista contém
    int count;
    
public:
    ListSingleLinked();
    void    print();                        //done
    void    add(int element);               //done
    void    add(int index, int element);    //done
    int     get(int index);                 //done
    int     set(int index, int element);    //done
    bool    remove(int element);            
    int     removeByIndex(int index);
    bool    isEmpty();
    int     size();
    bool    contains(int element);
    int     indexOf(int element);
    void    clear();                        //done
    std::string toString();
};

#endif
