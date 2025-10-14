// ******************************************
//  Classe abstrata TreeTAD
// ******************************************

class TreeTAD {
    public:
        virtual void addChild(Tree tree) = 0;
        virtual void addChild(int index, Tree tree) = 0;
        virtual Tree removeChild(int index) = 0;
        virtual Tree getChild(int index) = 0;
        virtual int  childrenCount() = 0;
        virtual int  size() = 0;        
        virtual int  getItem() = 0;
        virtual TreeTAD* getParent() = 0;
};

