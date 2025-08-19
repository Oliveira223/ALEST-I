// ******************************************
//  Classe abstrata ListTAD (INTERFACE)
// ******************************************

class ListTAD {
    public:
        virtual void print() = 0;
        virtual void add(int element) = 0;
        virtual void add(int element, int pos) = 0;
        virtual int get(int index) = 0;
        virtual int set(int index, int element) = 0;
        virtual bool remove(int element) = 0;
        virtual bool isEmpty() = 0;
        virtual int size() = 0;
        virtual int capacity() = 0;
        virtual bool contains(int element) = 0;
        virtual int indexOf(int element) = 0;
        virtual void clear() = 0;
};

