#include <iostream> 
#include <vector>
#include "TreeTAD.h"

using namespace std;

// virtual void addChild(TreeTAD* tree) = 0;
// virtual void addChild(int index, TreeTAD tree) = 0;
// virtual Tree removeChild(int index) = 0;
// virtual Tree getChild(int index) = 0;
// virtual int  childrenCount() = 0;
// virtual int  size() = 0;        
// virtual int  getItem() = 0;
// virtual TreeTAD* getParent() = 0;

// Classe Tree herda publicamente da classe TreeTAD (Classe Derivada)
//  | todos os membros publicos de TreeTAD permanecem publicos em Tree
class Tree : public TreeTAD{
    private: 
        TreeTAD* parent;
        int item;
        std::vector<TreeTAD*> children;

    public: 
        // Construtor
        Tree(int value){
            this -> item = value;
            this -> parent = nullptr;
        }
        ~Tree(){
            for( TreeTAD* child : children){
                delete child;
            }
        }

        void addChild(TreeTAD* child){
            // Adiciona um ponteiro a mais (tree) no vector de filhos do nó atual (this)
            children.push_back(child);
            Tree* treeChild = dynamic_cast<Tree*>(child);
            treeChild -> parent = this;
        }

        // Usando a ordem dos filhos no <vector> como indíce 
        void addChild(int index, TreeTAD* child){
            // Se indice válido
            if (index >= 0 && index <= children.size()){
                // Insere um elemento na posição dada e empurra os elem a direita para frente (indece, valor)
                children.insert(children.begin() + index, child);
                Tree* treeChild = dynamic_cast<Tree*>(child);
                treeChild -> parent = this;
            }
        }


        // Remove um nó filho na posição especificada (retorna o nó removido do tipo TreeTAD*)
        TreeTAD* removeChild(int index){
            if (index >= 0 && index < children.size()){
                Tree* removeChild = dynamic_cast<Tree*>(children[index]);
                children.erase(children.begin() + index);
                removeChild -> parent = nullptr; // Remove o pai do nó
                return removeChild;
            }
            return nullptr;
        }
    };



int main()
{
    Tree* tree = new Tree(10);
    tree->addChild(new Tree(2));
    delete tree;
    return 0;
}
