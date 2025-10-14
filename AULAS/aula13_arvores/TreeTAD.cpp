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

        void addChild(TreeTAD* tree){
            children.push_back(tree);
            Tree* tree2 = dynamic_cast<Tree*>(tree);
            tree2 -> parent = this;
        }

        void addChild(int index, TreeTAD* Tree){
            if (index >= 0 && index < children.size()){
            
            
            }
        }


        // Remove um nó filho na posição especificada
        TreeTAD* removeChild(int index){
            if (index >= 0 && index < children.size()){
                Tree* removeChild = dynamic_cast<Tree*>(children(index));
                child.erase(children.begin() + index);
                removeChild -> parent = nullptr; // Remove o pai do nó
                return removeChild;
            }
            return nullptr;
        }
    };



int main()
{
    Tree* tree = new Tree(10);

    return 0;
}
