#include <iostream>
#include "ABPTAD.h"

using namespace std;
/* 
    ====================== 
    EXEMPLO DYNAMIC_CAST<>

        ABPTAD* temp = valor;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);

        -> Como temp é do tipo ABPTAD e quero atribuir esse valor a uma TreeBinary, preciso converter o ABPTAD em TreeBinary
    =========================
*/
class TreeBinary : public ABPTAD{
private:
    ABPTAD* parent;                     // Ponteiro para o nó pai
    int item;                                  // Item armazenado no nó
    ABPTAD* left;
    ABPTAD* right;

    int alturaAux(ABPTAD*);
public:
    // Construtor
    TreeBinary(int value){
        this->item = value;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Destrutor
    ~TreeBinary() {
        delete left;              // Libera a memória dos filhos
        delete right;
    }

    void addLeft(ABPTAD* tree){
        this->left = tree;
    }
    void addRight(ABPTAD* tree){
        this->right = tree;
    }

    ABPTAD* removeLeft(){
        ABPTAD* temp = this->left;
        this->left = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }

    ABPTAD* removeRight(){
        ABPTAD* temp = this->right;
        this->right = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }

    // Obtém o item armazenado no nó
    int getItem() const {
        return item;
    }

    // Obtém o nó pai
    ABPTAD* getParent() const {
        return parent;
    }

    int altura(){
        int left = 0;
        int right = 0;
        ABPTAD* left2 = dynamic_cast<ABPTAD*>(this->left);
        ABPTAD* right2 = dynamic_cast<ABPTAD*>(this->right);
        if(this->left != nullptr){
            left = left2->altura();
        }
        if(this->right != nullptr){
            right = right2->altura();
        }
        if(left < right) return right + 1;
        return left + 1;
    }


    // =========================
    // Funções Novas
    // =========================
    void insert(int value){
        if(value > this -> item){
            if(this -> right == nullptr){
                this -> right = new TreeBinary(value);
                this -> right -> parent = this;
            } else{
                // Recurssão para a direita
                this -> right -> insert(value);
            }
        }

        if (value < this -> item){
            if(this -> left == nullptr){
                this -> left = new TreeBinary(value);
                this -> left -> parent = this;
            } else{
                // Recurssão para a esquerda
                this -> left -> insert(value);
            }
        }
    }

    bool contains(int value){

        return 0;
    }

    void remove(int value){

    }


};



//int main(){
//    Tree* arv = new Tree(1);
//    Tree* arv2 = new Tree(2);
//    arv->addChild(arv2);

//    cout << "Item do nó raiz: " << arv->getItem() << endl;
//    cout << "Size: " << arv->size() << endl;
//    cout << "Procurando 2: " << arv->dfs(1) << endl;
//}