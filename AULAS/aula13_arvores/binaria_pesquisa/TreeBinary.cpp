#include <iostream>
#include <vector>
#include "ABPTAD.h"

using namespace std;

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

    // Remoção: implementação mínima que só encaminha para filhos.
    // (Pode ser estendida para remoção completa de BST.)
    virtual void remove(int value) override
    {
        if (value < this->item)
        {
            if (this->left)
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
                if (t) t->remove(value);
            }
        }
        else if (value > this->item)
        {
            if (this->right)
            {
                TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
                if (t) t->remove(value);
            }
        }
        else
        {
            // Remoção do nó atual não implementada completamente aqui.
            // Mantido intencionalmente mínimo para compilar; estenda conforme necessário.
            cout << "remove(" << value << ") chamado — implementação completa não fornecida.\n";
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

    void printTree(int nivel = 0) const
    {
        for (int i = 0; i < nivel; ++i)
            cout << "  ";
        cout << this->item << endl;
        if (this->left)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->left);
            if (t)
                t->printTree(nivel + 1);
        }
        if (this->right)
        {
            TreeBinary *t = dynamic_cast<TreeBinary *>(this->right);
            if (t)
                t->printTree(nivel + 1);
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
    TreeBinary *arv = new TreeBinary(1);
    TreeBinary *arv2 = new TreeBinary(2);
    TreeBinary *arv3 = new TreeBinary(3);
    TreeBinary *arv4 = new TreeBinary(4);
    TreeBinary *arv5 = new TreeBinary(5);

    arv->addLeft(arv2);
    arv->addRight(arv3);
    arv2->addLeft(arv4);
    arv3->addRight(arv5);


    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Altura: " << arv->altura() << endl;

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
    
    delete arv;
    return 0;
}