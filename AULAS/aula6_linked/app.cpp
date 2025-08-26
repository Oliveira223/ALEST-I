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

    // Teste ADD
    lista.add(2); lista.add(4);  lista.add(6);
    lista.add(8); lista.add(10); lista.print();
    
    // ADD Constante
    lista.add(1, 5);
    lista.print();

    // Teste get()
    cout << lista.get(1) << endl;
    cout << lista.get(6) << endl;
    
    // Teste set();
    cout << lista.set(1, 3) << endl; lista.print();
    cout << lista.set(6, 4) << endl; lista.print();

    // Teste Remove By Index
    cout << lista.removeByIndex(5) << endl; lista.print();
    cout << lista.removeByIndex(0) << endl; lista.print();

    // Teste Remove
    cout << lista.remove(4) << endl; lista.print();
    cout << lista.remove(0) << endl; lista.print();

    

    // Limpando Lista
    lista.clear();
    lista.print();
}
