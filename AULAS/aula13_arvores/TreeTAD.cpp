#include <iostream> 
#include <vector>
#incclude "TreeTAD.h"

using namespace std;

class Tree : public TreeTad{
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
    }