#include <iostream>
#include "TreeBinaryTAD.h"

using namespace std;

class TreeBinary : public TreeBinaryTAD{
private:
    TreeBinaryTAD* parent;                   // Ponteiro para o nó pai
    int item;                                // Item armazenado no nó
    TreeBinaryTAD* left;
    TreeBinaryTAD* right;
    int alturaAux(TreeBinaryTAD*);
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

    void addLeft(TreeBinaryTAD* tree){
        this->left = tree;
        TreeBinary* child = dynamic_cast<TreeBinary*>(tree);
        if(child) child->parent = this;
    }
    void addRight(TreeBinaryTAD* tree){
        this->right = tree;
        TreeBinary* child = dynamic_cast<TreeBinary*>(tree);
        if(child) child->parent = this;
    }

    TreeBinaryTAD* removeLeft(){
        TreeBinaryTAD* temp = this->left;
        this->left = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }
    TreeBinaryTAD* removeRight(){
        TreeBinaryTAD* temp = this->right;
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
    TreeBinaryTAD* getParent() const {
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



    // Adiciona um nó filho
    void addChild(TreeTAD* tree) {
       children.push_back(tree);
       Tree* tree2 = dynamic_cast<Tree*>(tree);
       tree2->parent = this;           // Define o pai do nó filho
    }


    // // Adiciona um nó filho em uma posição específica
    // void addChild(int index, TreeTAD* tree) {
    //    if (index >= 0 && index <= children.size()) {
    //        children.insert(children.begin() + index, tree);
    //        Tree* tree2 = dynamic_cast<Tree*>(tree);
    //        tree2->parent = this;       // Define o pai do nó filho
    //    }
    // }

    // // Remove um nó filho na posição especificada
    // TreeTAD* removeChild(int index) {
    //    if (index >= 0 && index < children.size()) {
    //        Tree* removedChild = dynamic_cast<Tree*>(children[index]);
    //        children.erase(children.begin() + index);
    //        removedChild->parent = nullptr; // Remove o pai do nó
    //        return removedChild;
    //    }
    //    return nullptr;
    // }

    // // Obtém um nó filho na posição especificada
    // TreeTAD* getChild(int index) {
    //    if (index >= 0 && index < children.size()) {
    //        return children[index];
    //    }
    //    return nullptr;
    // }

    // // Conta o número de filhos
    // int childrenCount() const {
    //    return children.size();
    // }

    // // Obtém o tamanho da árvore (neste exemplo, o número de nós)
    // int size() const {
    //    int totalSize = 1; // Contando o nó atual
    //    for (TreeTDA* child : children) {
    //        totalSize += child->size(); // Contando nós filhos
    //    }
    //    return totalSize;
    // }

    // bool dfs(int value){
    //    if(this->item == value) return true;
    //    for(TreeTDA* filho : children){
    //        Tree* filho2 = dynamic_cast<Tree*>(filho);
    //        if(filho2->dfs(value))return true;
    //    }
    //    return false;
    // }

};



int main(){
   // Criando raiz e dois filhos
   TreeBinary* raiz = new TreeBinary(10);
   TreeBinary* left = new TreeBinary(5);
   TreeBinary* right = new TreeBinary(15);

   // Liga os nós (addLeft/addRight agora também definem parent)
   raiz->addLeft(left);
   raiz->addRight(right);

   cout << "Item da raiz: " << raiz->getItem() << endl;
   cout << "Item left: " << left->getItem() << endl;
   cout << "Item right: " << right->getItem() << endl;
   cout << "Altura da árvore (raiz): " << raiz->altura() << endl;

   // Libera memória (destrutor de raiz deleta recursivamente filhos)
   delete raiz;
   return 0;
}