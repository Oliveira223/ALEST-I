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

    cout << "\n> Posição do elemento 8:\n" << lista->indexOf(8) << endl;
    cout << "\n> Posição do elemento 22:\n" << lista->indexOf(22) << endl;
    cout << "\n> Existe o elemento 22? \n" << lista->contains(22) << endl;
    cout << "\n> Elemento armazenado na primeira posicao da lista: \n" << lista->get(0) << endl;
    cout << "\n> Elemento armazenado na ultima posicao da lista: \n" << lista->get(lista->size() - 1) << endl;


    cout << "\n> Alterando o terceiro elemento para 30" << endl;
    lista->set(2, 30);
    lista->print();

    cout << "\n> Inserindo o 7 na quinta posição" << endl;
    lista->add(4, 7);
    lista->print();

    cout << "\n> Inserindo o 11 na última posição" << endl;
    lista->add(lista->size() - 1, 11);
    lista->print();

    cout << "\n>Removendo o elemento 30" << endl;
    lista->remove(30);
    lista->print();

    cout << "\n> Removendo o elemento na posição 3" << endl;
    lista->removeByIndex(3);
    lista->print();

    cout << "\n> Adicionando no Inicio" << endl;
    lista-> addFirst(10);
    lista-> print();


    cout << "\n>Pegando Inicio" << endl;
    cout << lista-> getFirst();
    lista-> print();

    
    cout << "\n> Pegando ultimo" << endl;
    cout << lista-> getLast();
    lista-> print();
    
    cout << "\n> Removendo do inicio" << endl;
    lista-> removeFirst();
    lista-> print();

    cout << "\n> Removendo do final" << endl;
    lista-> removeLast();
    lista-> print();


    cout << "\n> Tamanho da lista: " << lista->size() << endl;
    cout << "\n> A lista está vazia? " << (lista->isEmpty() ? "Sim" : "Não") << endl;
    cout << "\n> Limpando a lista..." << endl;
    lista->clear();
    lista->print();
    
     return 0;
}
