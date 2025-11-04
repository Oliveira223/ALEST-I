class ABPTAD {
    public:
        // Adicionar um nó filho
        virtual void insert(int value) = 0;
  
        // Remover uma chave especifica             
        virtual bool contains(int value) = 0;

        // Remover uma chave
        virtual void remove(int value) = 0;
};