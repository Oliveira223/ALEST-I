#include <iostream>
#include "ListDoubleLinked.h"

using namespace std;

// ******************************************
//  Programa principal
// ******************************************
int main()
{
    ListDoubleLinked *lista = new ListDoubleLinked();

    lista->add(2);
    lista->add(4);
    lista->add(6);
    lista->add(8);
    lista->add(10);

    lista->print();

    lista->add(0, 1);

    cout << "Posição do elemento 8:" << lista->indexOf(8) << endl;
    cout << "Posição do elemento 22:" << lista->indexOf(22) << endl;
    cout << "Existe o elemento 22? " << lista->contains(22) << endl;
    cout << "Elemento armazenado na primeira posicao da lista: " << lista->get(0) << endl;
    cout << "Elemento armazenado na ultima posicao da lista: " << lista->get(lista->size() - 1) << endl;


    cout << "\nAlterando o terceiro elemento para 30" << endl;
    lista->set(2, 30);
    lista->print();

    cout << "\nInserindo o 7 na quinta posição" << endl;
    lista->add(4, 7);
    lista->print();

    cout << "\nInserindo o 11 na última posição" << endl;
    lista->add(lista->size() - 1, 11);
    lista->print();

    cout << "\nRemovendo o elemento 30" << endl;
    lista->remove(30);
    lista->print();

    cout << "\nRemovendo o elemento na posição 3" << endl;
    lista->removeByIndex(3);
    lista->print();

    cout << "\nTamanho da lista: " << lista->size() << endl;
    cout << "A lista está vazia? " << (lista->isEmpty() ? "Sim" : "Não") << endl;
    cout << "\nLimpando a lista..." << endl;
    lista->clear();
    lista->print();
    
     return 0;
}
