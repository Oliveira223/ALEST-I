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

    // Retorna referência privada do numero de filhos
    const std::vector<TreeTAD*>& getChildren() const {
        return children;
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

// Função verificar ordem
//  > 1 nó dois niveis acima
//  ou 
//  > 3 nós um nível acima
bool verificar(Tree* node){
    if (!node) return false;
    if (!node->getParent()){
        cout << "É a raiz" << endl;
        return true;
    }
    
    // Primeira opção: Verifica se existe alguém 2 niveis acima
    Tree* primeiroPai = dynamic_cast<Tree*>(node->getParent());
    if(primeiroPai){
        Tree* segundoPai = dynamic_cast<Tree*>(primeiroPai->getParent());
        if(segundoPai){
            return true;
        }
    }

    // Segunda opção: Verifica se existe 3 pessoas um nivel acima
    if (primeiroPai && primeiroPai->getChildren().size() >= 3) {
        return true;
    }

    return false;
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
        //Tira aspas
        if (!nome.empty() && nome.front() == '"') nome.erase(0,1);
        if (!nome.empty() && nome.back() == '"') nome.pop_back();
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

    cout << "\n=== Verificação de Condições ===\n" << endl;
    // Verifica a condição para o nó "Ana"
    for (Tree* no : nos) {
        if (no->getItem() == "Ana") { 
            if (verificar(no)) {
                cout << "Ana atende à condição." << endl;
            } else {
                cout << "Ana não atende à condição." << endl;
            }
            break;
        }
    }

    delete raiz; // libera memória
    return 0;



}