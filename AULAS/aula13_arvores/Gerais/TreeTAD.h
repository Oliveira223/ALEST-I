// ******************************************
//  Classe abstrata TreeTAD
// ******************************************

// É o tipo absatrato de dados genérico para que outros tipos de arvore possam usar o mesmo TAD

class TreeTAD {
    public:
        virtual void addChild(TreeTAD* tree) = 0;
        virtual void addChild(int index, TreeTAD* tree) = 0;
        virtual TreeTAD* removeChild(int index) = 0;
        virtual TreeTAD* getChild(int index) = 0;
        virtual int  childrenCount() = 0;
        virtual int  size() = 0;        
        virtual int  getItem() = 0;
        virtual TreeTAD* getParent() = 0;

        // virtual string toString() = 0;
        // virtual int size() = 0;
        // virtual int ascendentes(int item) = 0;
};

