CPPFLAGS = -Wall -g    # Opções do compilador: todos warnings e debug info

PROG = app
FONTES = app.cpp stackLinkedList.cpp ../aula6_linked/ListSingleLinked.cpp ../aula6_linked/Node.cpp
OBJETOS = $(FONTES:.cpp=.o)

# Regra padrão para compilar o programa
$(PROG): $(OBJETOS)
	g++ $(CPPFLAGS) $(OBJETOS) -o $@

# Regra para compilar cada .cpp em .o
%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	-@rm -f $(OBJETOS) $(PROG)

# Regra para facilitar a recompilação total
all: clean $(PROG)
