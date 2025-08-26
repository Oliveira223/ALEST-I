#include <iostream>
#include "ListSingleLinked.h"

using namespace std;

// ==========================================
//  Programa principal
// ==========================================
int main()
{
    ListSingleLinked lista;

    lista.print();
    lista.add(2);
    lista.add(4);
    lista.add(6);
    lista.add(8);
    lista.add(10);
    lista.print();
    
    lista.add(1, 5);
    lista.print();

    cout << lista.get(1) << endl;
    cout << lista.get(6) << endl;
    cout << lista.set(1, 3) << endl;
    lista.print();
    cout << lista.set(6, 4) << endl;
    lista.print();

    cout << lista.removeByIndex(5) << endl;
    lista.print();

    // cout << lista.removeByIndex(0) << endl;
    // lista.print();

    
    lista.clear();
    lista.print();


    

   // cout << lista.toString() << endl;

    // cout << "Elemento armazenado na primeira posicao da lista: " << lista.get(0) << endl;
    // cout << "Elemento armazenado na ultima posicao da lista: " << lista.get(lista.size() - 1) << endl;
    // cout << "Posição do 8: " << lista.indexOf(8) << endl;

    // bool ok = lista.remove(6);
    // cout << endl;
    // if (ok)
    //     cout << "OK! Consegui remover!" << endl;
    // else
    //     cout << "Elemento não existe" << endl;
    // cout << lista.toString();
}
