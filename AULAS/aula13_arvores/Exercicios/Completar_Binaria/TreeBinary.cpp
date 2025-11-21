#include <iostream>
#include <string>
#include "TreeBinaryTDA.h"

using namespace std;

class TreeBinary : public TreeBinaryTDA{
private:
    TreeBinaryTDA* parent;                     // Ponteiro para o nó pai
    int item;                         // Item armazenado no nó
    TreeBinaryTDA* left;
    TreeBinaryTDA* right;

    int alturaAux(TreeBinaryTDA*);
    void printRec(const TreeBinary* node, const std::string& prefix, bool isLeft) const;
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
        TreeBinary* child = dynamic_cast<TreeBinary*>(tree);
        if(child) child->parent = this;
    }
    void addRight(TreeBinaryTDA* tree){
        this->right = tree;
        TreeBinary* child = dynamic_cast<TreeBinary*>(tree);
        if(child) child->parent = this;
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

    void print() const;

    
    // //Novos (Ex 3)
    // virtual int size() const = 0;        -- done
    // virtual int degree() const = 0;      -- done
    // virtual int level() const = 0
    // virtual int height() const = 0;      -- done
    
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

    
    // Retorna o numero de filhos imediatamente abaixo (nas binarias: 0. 1 ou 2)
    int degree() const{
        const TreeBinary* left2 = dynamic_cast<const TreeBinary*>(this->left);
        const TreeBinary* right2 = dynamic_cast<const TreeBinary*>(this->right);
        // Condition ? if_true : if_false
        return (left2 ? 1 : 0) + (right2 ? 1 : 0);
    }

    // Retorna o número de arestas até o pai
    int level() const{
        const TreeBinary* p = dynamic_cast<const TreeBinary*>(this->parent);
        // Se p existe: retorna 1 + recursão, se não retorna 0
        return p ? 1 + p->level() : 0;
    }

    int height() const{
        int left = 0;
        int right = 0;
        const TreeBinary* left2 = dynamic_cast<const TreeBinary*>(this->left);
        const TreeBinary* right2 = dynamic_cast<const TreeBinary*>(this->right);
        if(this->left != nullptr){
            left = left2->height();
        }
        if(this->right != nullptr){
            right = right2->height();
        }
        if(left < right) return right + 1;
        return left + 1;
    }   
    

};

// Implementação das funções de impressão
void TreeBinary::printRec(const TreeBinary* node, const std::string& prefix, bool isLeft) const{
    if(node == nullptr) return;
    std::cout << prefix << "|- " << node->getItem() << std::endl;

    std::string childPrefix = prefix + (isLeft ? "|   " : "    ");

    const TreeBinary* leftN = dynamic_cast<const TreeBinary*>(node->left);
    const TreeBinary* rightN = dynamic_cast<const TreeBinary*>(node->right);

    if(leftN) printRec(leftN, childPrefix, true);
    if(rightN) printRec(rightN, childPrefix, false);
}

void TreeBinary::print() const {
    // Imprime raiz sem prefixo
    std::cout << this->getItem() << std::endl;
    const TreeBinary* leftN = dynamic_cast<const TreeBinary*>(this->left);
    const TreeBinary* rightN = dynamic_cast<const TreeBinary*>(this->right);
    if(leftN) printRec(leftN, "", true);
    if(rightN) printRec(rightN, "", false);
}



int main(){
    TreeBinaryTDA* arv = new TreeBinary(1);
    TreeBinaryTDA* arv2 = new TreeBinary(2);
    TreeBinaryTDA* arv3 = new TreeBinary(3);
    TreeBinaryTDA* arv4 = new TreeBinary(4);
    TreeBinaryTDA* arv5 = new TreeBinary(5);
    TreeBinaryTDA* arv6 = new TreeBinary(6);
    arv->addLeft(arv2);
    arv->addRight(arv3);
    arv2->addLeft(arv4);
    arv2->addRight(arv5);
    arv5->addRight(arv6);
    
    cout << "\nImprimindo árvore em estilo hierarquia:\n";
    arv->print();
    
    cout << "\nTestes ===================================" << endl;
    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Size: "            << arv->size()    << endl;
    cout << "Altura:"           << arv->height()  << endl;
    cout << "Grau: "            << arv->degree()  << endl;
    cout << "Grau do nó 5: "    << arv5->degree() << endl;
    cout << "Nivel do nó 5: "   << arv5->level()  << endl;  
    cout << "Nivel do nó 2: "   << arv2->level()  << endl;  
    cout << "Nivel do nó 1: "   << arv->level()  << endl;    
 
    delete arv; // deleta árvore (destrutor cuida dos filhos)
 }