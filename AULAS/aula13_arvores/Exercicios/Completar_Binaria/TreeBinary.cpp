#include <iostream>
#include "TreeBinaryTDA.h"

using namespace std;

class TreeBinary : public TreeBinaryTDA{
private:
    TreeBinaryTDA* parent;                     // Ponteiro para o nó pai
    int item;                         // Item armazenado no nó
    TreeBinaryTDA* left;
    TreeBinaryTDA* right;

    int alturaAux(TreeBinaryTDA*);
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

    void addLeft(TreeBinaryTDA* tree){
        this->left = tree;
    }
    void addRight(TreeBinaryTDA* tree){
        this->right = tree;
    }

    TreeBinaryTDA* removeLeft(){
        TreeBinaryTDA* temp = this->left;
        this->left = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }
    TreeBinaryTDA* removeRight(){
        TreeBinaryTDA* temp = this->right;
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
    TreeBinaryTDA* getParent() const {
        return parent;
    }

    int altura(){
        int left = 0;
        int right = 0;
        TreeBinary* left2 = dynamic_cast<TreeBinary*>(this->left);
        TreeBinary* right2 = dynamic_cast<TreeBinary*>(this->right);
        if(this->left != nullptr){
            left = left2->altura();
        }
        if(this->right != nullptr){
            right = right2->altura();
        }
        if(left < right) return right + 1;
        return left + 1;
    }   


    // //Novos (Ex 3)
    // virtual int size() const = 0;
    // virtual int degree() const = 0;
    // virtual int level() const = 0
    // virtual int height() const = 0;

    // Retorna a quantidade de nós
    int size() const{
        int tamanho = 1; // conta o nó atual
        if(this->left != nullptr){
            tamanho += this->left->size();
        }

        if(this->right != nullptr){
            tamanho += this->right->size();
        }

        return tamanho;
    }
};



int main(){
    TreeBinaryTDA* arv = new TreeBinary(1);
    TreeBinaryTDA* arv2 = new TreeBinary(2);
    arv->addLeft(arv2);

    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Size: " << arv->size() << endl;

    delete arv; // deleta árvore (destrutor cuida dos filhos)
 }