
// ******************************************
//  Classe abstrata TreeTAD
// ******************************************

// É o tipo abstrato de dados genérico para que outros tipos de árvore possam usar o mesmo TAD

#ifndef TREETAD_H
#define TREETAD_H

#include <string>

class TreeTAD {
    public:
        virtual ~TreeTAD() {}

        // Adiciona um filho (implementação concreta decide como usar índice, se necessário)
        virtual void addChild(TreeTAD* tree) = 0;

        // Retorna o número de nós na subárvore
        virtual int size() = 0;

        
        // Retorna o ponteiro para o pai (ou nullptr se raiz)
        virtual TreeTAD* getParent() = 0;

        // Retorna filho no index
        virtual TreeTAD* getChild(int index) = 0;

        // Conta ascendentes que correspondem ao item (string)
        virtual int ascendentes(const std::string& item) = 0;
};

#endif // TREETAD_H

