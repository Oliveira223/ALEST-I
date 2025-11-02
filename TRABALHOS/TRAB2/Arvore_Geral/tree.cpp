#include "TreeTAD.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Tree : public TreeTAD{
private:
    TreeTAD* parent;                     // Ponteiro para o nó pai
    string item;                         // Item armazenado no nó
    std::vector<TreeTAD*> children;      // Vetor para armazenar nós filhos

public:
    // Construtor
    Tree(string value){
        this->item = value;
        this->parent = nullptr;
    }

    // Destrutor
    ~Tree() {
        for (TreeTAD* child : children) {
            delete child;              // Libera a memória dos filhos
        }
    }

    // Adiciona um nó filho
    void addChild(TreeTAD* tree) {
        children.push_back(tree);
        Tree* tree2 = dynamic_cast<Tree*>(tree);
        if (tree2) {
            tree2->parent = this;           // Define o pai do nó filho
        }
    }

    // Obtém o tamanho da árvore (n° de nós)
    int size() {
        int totalSize = 1; // Contando o nó atual
        for (TreeTAD* child : children) {
            totalSize += child->size(); // Contando nós filhos
        }
        return totalSize;
    }

    // Obtém o item armazenado no nó
    const string& getItem() const {
        return item;
    }

    // Obtém o nó pai
    TreeTAD* getParent(){
        return parent;
    }

    // Obtém um nó filho na posição especificada
    TreeTAD* getChild(int index) {
        if (index >= 0 && index < static_cast<int>(children.size())) {
            return children[index];
        }
        return nullptr;
    }

    // Retorna referência const ao vetor de filhos para iteração
    const std::vector<TreeTAD*>& getChildren() const {
        return children;
    }

    // Retorna quantos nós acima possuem o item especificado
    int ascendentes(const string& target) {
        int count = 0;

        // Começa do nó pai e sobe até a raiz
        TreeTAD* current = this->parent;

        // Enquanto houver um nó pai
        while (current != nullptr) {
            Tree* currentTree = dynamic_cast<Tree*>(current);
            if (currentTree == nullptr) {
                // Se o ancestral não for do tipo Tree, sobe pela interface base
                current = current->getParent();
                continue;
            }

            if (currentTree->getItem() == target) {
                count++;
            }

            // Move para o próximo nó pai
            current = currentTree->getParent();
        }
        return count;
    }
};

void printTree(Tree* node, int nivel = 0) {
    if (!node) return;
    for (int i = 0; i < nivel; ++i) cout << "  ";
    cout << node->getItem() << endl;
    for (TreeTAD* child : node->getChildren()) {
        Tree* childTree = dynamic_cast<Tree*>(child);
        if (childTree) {
            printTree(childTree, nivel + 1);
        }
    }
}

int main(){
    // ==========================
    // LEITURA DO ARQUIVO
    // ==========================
    ifstream file("../nomes.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    int n;
    if (!(file >> n)) {
        cerr << "Formato inválido: não conseguiu ler o número de nós." << endl;
        return 1;
    }

    vector<string> nomes;
    string nome;
    while (file >> nome) {
        nomes.push_back(nome);
    }
    file.close();

    if (nomes.empty()) {
        cerr << "Arquivo não contém pares de nomes." << endl;
        return 1;
    }

    // Teste imprimir pares 
    for (size_t i = 0; i + 1 < nomes.size(); i += 2){
        cout << nomes[i] << " -> " << nomes[i + 1] << endl;
    }

    // =========================
    // CRIAÇÃO DA HIERARQUIA
    // =========================
    vector<Tree*> nos;
    Tree* raiz = new Tree(nomes[0]);
    nos.push_back(raiz);

    Tree* pai_atual = raiz;
    string pai_anterior = nomes[0];

    for (size_t i = 0; i + 1 < nomes.size(); i += 2) {
        string paiNome = nomes[i];
        string filhoNome = nomes[i + 1];

        // Se o pai mudou, encontra o nó correspondente na lista
        if (paiNome != pai_anterior) {
            for (Tree* no : nos) {
                if (no->getItem() == paiNome) {
                    pai_atual = no;
                    break;
                }
            }
            pai_anterior = paiNome;
        }

        Tree* filho = new Tree(filhoNome);
        pai_atual->addChild(filho);
        nos.push_back(filho);
    }

    cout << "\n=== Estrutura da Árvore ===\n";
    printTree(raiz);

    delete raiz; // libera memória
    return 0;


    
}