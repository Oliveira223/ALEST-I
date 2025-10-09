#ifndef TREE_H
#define TREE_H

#include <string>
#include "TreeTAD.h"

using namespace std;

// ******************************************
//  Classe Tree
// ******************************************

class Tree : public Tree
{
private:
    Tree* tree;

public:
    Tree parent;
    E item;
    Tree(E, item);
    void addChild(Tree tree);
    void addChild(int index, Tree tree);
    Tree removeChild(int index);
    Tree getChild(int index);
    int childrenCount();
    int size();
};

#endif
