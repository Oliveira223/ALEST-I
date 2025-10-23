#include <iostream>
#include <vector>
#include "TreeTAD.h"

using namespace std;

class Tree : public TreeTAD{
private:
    TreeTAD* parent;                     // Ponteiro para o nó pai
    int item;                         // Item armazenado no nó
    std::vector<TreeTAD*> children;      // Vetor para armazenar nós filhos

public:
    // Construtor
    Tree(int value){
        this->item = value;
        this->parent = nullptr;
    }

    // Destrutor
    ~Tree() {
        for (TreeTAD* child : children) {
            delete child;              // Libera a memória dos filhos
        }
    }

    // Adiciona um nó filho
    void addChild(TreeTAD* tree) {
        children.push_back(tree);
        Tree* tree2 = dynamic_cast<Tree*>(tree);
        tree2->parent = this;           // Define o pai do nó filho
    }


    // Adiciona um nó filho em uma posição específica
    void addChild(int index, TreeTAD* tree) {
        if (index >= 0 && index <= children.size()) {
            children.insert(children.begin() + index, tree);
            Tree* tree2 = dynamic_cast<Tree*>(tree);
            tree2->parent = this;       // Define o pai do nó filho
        }
    }

    // Remove um nó filho na posição especificada
    TreeTAD* removeChild(int index) {
        if (index >= 0 && index < children.size()) {
            Tree* removedChild = dynamic_cast<Tree*>(children[index]);
            children.erase(children.begin() + index);
            removedChild->parent = nullptr; // Remove o pai do nó
            return removedChild;
        }
        return nullptr;
    }

    // Obtém um nó filho na posição especificada
    TreeTAD* getChild(int index) {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }

    // Conta o número de filhos
    int childrenCount() {
        return children.size();
    }

    // Obtém o tamanho da árvore (neste exemplo, o número de nós)
    int size() {
        int totalSize = 1; // Contando o nó atual
        for (TreeTAD* child : children) {
            totalSize += child->size(); // Contando nós filhos
        }
        return totalSize;
    }

    // Obtém o item armazenado no nó
    int getItem() {
        return item;
    }

    // Obtém o nó pai
    TreeTAD* getParent(){
        return parent;
    }
    
};


int main(){
    Tree* arv = new Tree(1);
    Tree* arv2 = new Tree(2);
    arv->addChild(arv2);

    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Size: " << arv->size() << endl;
    
}