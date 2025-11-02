// ******************************************
//  Classe abstrata TreeTAD
// ******************************************

// É o tipo abstrato de dados genérico para que outros tipos de árvore possam usar o mesmo TAD

#ifndef TREETAD_H
#define TREETAD_H

#include <string>
#include <vector>

class TreeTAD {
public:
    virtual ~TreeTAD() = default;

    // Manipulação de filhos
    virtual void addChild(TreeTAD* child) = 0;
    virtual TreeTAD* getChild(int index) = 0;
    virtual const std::vector<TreeTAD*>& getChildren() const = 0;

    // Informações do nó
    virtual int size() = 0;
    virtual const std::string& getItem() const = 0;
    virtual TreeTAD* getParent() = 0;
};

#endif // TREETAD_H

