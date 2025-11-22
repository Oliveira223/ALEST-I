#include <iostream>
#include <vector>
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

class TreeBinary : public ABPTAD
{
private:
    ABPTAD *parent; // Ponteiro para o nó pai
    int item;       // Item armazenado no nó
    ABPTAD *left;
    ABPTAD *right;

public:
    // Construtor
    TreeBinary(int value) : parent(nullptr), item(value), left(nullptr), right(nullptr) {}

    // Destrutor
    ~TreeBinary()
    {
        if (left)
            delete left; // Libera a memória dos filhos (recursivo)
        if (right)
            delete right;
    }

    void addLeft(ABPTAD *tree)
    {
        this->left = tree;
        if (tree)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(tree);
            if (t)
                t->parent = this;
        }
    }
    void addRight(ABPTAD *tree)
    {
        this->right = tree;
        if (tree)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(tree);
            if (t)
                t->parent = this;
        }
    }

    ABPTAD *removeLeft()
    {
        ABPTAD *temp = this->left;
        this->left = nullptr;
        TreeBinary *treeTemp = dynamic_cast<TreeBinary *>(temp);
        if (treeTemp)
            treeTemp->parent = nullptr;
        return temp;
    }

    ABPTAD *removeRight()
    {
        ABPTAD *temp = this->right;
        this->right = nullptr;
        TreeBinary *treeTemp = dynamic_cast<TreeBinary *>(temp);
        if (treeTemp)
            treeTemp->parent = nullptr;
        return temp;
    }

    // Obtém o item armazenado no nó
    int getItem() const
    {
        return item;
    }

    // Obtém o nó pai
    ABPTAD *getParent() const
    {
        return parent;
    }

    int altura()
    {
        int left_h = 0;
        int right_h = 0;
        if (this->left)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
            if (t)
                left_h = t->altura();
        }
        if (this->right)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
            if (t)
                right_h = t->altura();
        }
        return (left_h < right_h ? right_h : left_h) + 1;
    }

    // Implementação das funções virtuais puras de ABPTAD
    virtual bool contains(int value) override
    {
        if (value == this->item) return true;
        if (value < this->item)
        {
            if (this->left)
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
                if (t) return t->contains(value);
            }
            return false;
        }
        else
        {
            if (this->right)
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
                if (t) return t->contains(value);
            }
            return false;
        }
    }

    // Ao remover o item é necessário que a arvore ainda satisfaça o criterio de organzição
    // Primeiro, localiza-se o elemento a ser excluido e salve o endereço do seu pai
    // A seguir, veririfica se é folha ou se tem filhos
    // > Se folha: tornar nó vazio
    // > Se um filho: colocar filho no lugar
    // > se 2 filhos: localizar o maior elemento da subárvore esquerda ou o menor da subárvore direita para substituir o nó removido

    virtual void remove(int value) override
    {
        // Localizar Elemento
        if (this == value)
        {
                
        }
        

    }

    // =========================
    // Funções Novas
    // =========================
    void insert(int value)
    {
        if (value > this->item)
        {
            if (this->right == nullptr)
            {
                TreeBinary *nb = new TreeBinary(value);
                nb->parent = this;
                this->right = nb;
            }
            else
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
                if (t)
                    t->insert(value);
            }
        }
        else if (value < this->item)
        {
            if (this->left == nullptr)
            {
                TreeBinary *nb = new TreeBinary(value);
                nb->parent = this;
                this->left = nb;
            }
            else
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
                if (t)
                    t->insert(value);
            }
        }
    }

    void printTree(const std::string &prefix = "", bool isLast = true, bool isRoot = true) const
    {
        // Imprime nó atual (raiz não imprime conector)
        if (isRoot)
        {
            std::cout << this->item << std::endl;
        }
        else
        {
            std::cout << prefix << (isLast ? "└─ " : "├─ ") << this->item << std::endl;
        }

        // Coleta filhos em ordem (esquerda, direita)
        std::vector<ABPTAD *> childs;
        if (this->left)
            childs.push_back(this->left);
        if (this->right)
            childs.push_back(this->right);

        // Itera sobre filhos e chama recursivamente
        for (size_t i = 0; i < childs.size(); ++i)
        {
            ABPTAD *c = childs[i];
            bool last = (i == childs.size() - 1);
            TreeBinary *t = dynamic_cast<TreeBinary *>(c);
            if (t)
            {
                std::string newPrefix;
                if (isRoot)
                    newPrefix = ""; // filhos da raiz começam sem prefixo adicional
                else
                    newPrefix = prefix + (isLast ? "   " : "│  ");
                t->printTree(newPrefix, last, false);
            }
        }
    }

    int factor()
    {
        int rh = 0, lh = 0;
        if (this->right)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
            if (t)
                rh = t->altura();
        }
        if (this->left)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
            if (t)
                lh = t->altura();
        }
        return (rh - lh);
    }

    void TreeToVector(vector<int> *V)
    {
        if (!V)
            return;
        if (this->left)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
            if (t)
                t->TreeToVector(V);
        }
        V->push_back(this->item);
        if (this->right)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
            if (t)
                t->TreeToVector(V);
        }
    }

    void OrdenedVector(vector<int> *V)
    {
        if (!V)
            return;
        
        // Bubble Sort simples
        for (size_t i = 0; i < V->size(); ++i)
        {
            for (size_t j = 0; j < V->size() - 1 - i; ++j)
            {
                if ((*V)[j] > (*V)[j + 1])
                {
                    swap((*V)[j], (*V)[j + 1]);
                }
            }
        }

    }
};

int main()
{
    TreeBinary *arv = new TreeBinary(5);
    // TreeBinary *arv2 = new TreeBinary(2);
    // TreeBinary *arv3 = new TreeBinary(3);
    // TreeBinary *arv4 = new TreeBinary(4);
    // TreeBinary *arv5 = new TreeBinary(5);

    // arv->addLeft(arv2);
    // arv->addRight(arv3);
    // arv2->addLeft(arv4);
    // arv3->addRight(arv5);
    
    arv->insert(1);
    arv->insert(3);
    arv->insert(4);
    arv->insert(2);
    arv->insert(8);
    arv->insert(9);
    arv->insert(6);
    arv->insert(7);
    
    // Transforma Arvore em Vetor
    vector<int> Tree_Vec;
    arv->TreeToVector(&Tree_Vec);
    cout << "Arvore em Vetor: ";
    for (int val : Tree_Vec)
    {
        cout << val << " ";
    }
    cout << endl;
    
    // Ordena Vetor
    arv->OrdenedVector(&Tree_Vec);
    cout << "Vetor Ordenado: ";
    for (int val : Tree_Vec)
    {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Árvore:" << endl;
    arv->printTree();
    
    cout << "Testes ========================="          << endl;
    cout << "Item do nó raiz: " << arv->getItem()       << endl;
    cout << "Altura: " << arv->altura()                 << endl;
    cout << "Fator: "  << arv->factor()                 << endl;
    cout << "\n Removendo elementos: \n > Removendo 9 e 2" 
         << arv->remove(9)                             
         << arv->remove(2)                              << endl;

    arv->printTree();




    delete arv;
    return 0;
}