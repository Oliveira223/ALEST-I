class TreeBinaryTDA {
public:
    virtual ~TreeBinaryTDA() {}
    virtual void addLeft(TreeBinaryTDA* tree) = 0;
    virtual void addRight(TreeBinaryTDA* tree) = 0;
    virtual TreeBinaryTDA* removeLeft() = 0;
    virtual TreeBinaryTDA* removeRight() = 0;
    virtual int getItem() const = 0;
    virtual TreeBinaryTDA* getParent() const = 0;

    //Novos (Ex 3)
    virtual int size() const = 0;
    // virtual int degree() const = 0;
    // virtual int level() const = 0;
    // virtual int height() const = 0;
    
};