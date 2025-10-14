#include <iostream> 
#include <vector>
#incclude "TreeTAD.h"

using namespace std;

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
                delete child
            }
        }

        void addChild(TreeTAD* tree){
            children.push_back(tree)
            Tree* tree2 = dynamic_cast<Tree*>(tree);
            tree2 -> parent = this;
        }
    }
