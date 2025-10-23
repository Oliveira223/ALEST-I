#include "TreeTAD.h"
#include <iostream>

using namespace std;

int main() {
    Tree* root = new Tree(10);

    Tree* n1 = new Tree(20);
    Tree* n2 = new Tree(30);
    Tree* n3 = new Tree(40);

    root->addChild(n1);
    root->addChild(n2);
    root->addChild(n3);

    n1->addChild(new Tree(21));
    n1->addChild(new Tree(22));

    n2->addChild(new Tree(31));

    n3->addChild(new Tree(41));
    n3->addChild(new Tree(42));
    n3->addChild(new Tree(43));

    cout << "Árvore completa:" << endl;
    root->print();

    TreeTAD* removed = n3->removeChild(1); // remove o 42
    cout << "\nApós remover um nó:" << endl;
    root->print();

    delete removed;
    delete root;

    return 0;
}
