CPPFLAGS = -Wall -g    # Opções do compilador: todos warnings e debug info

PROG = app
#FONTES = app.cpp Node.cpp queuearray.cpp
FONTES = app.cpp queueListLinked.cpp 
OBJETOS = $(FONTES:.cpp=.o)

$(PROG): $(OBJETOS)
	g++ $(CPPFLAGS) $(OBJETOS) -o $@

clean:
	-@ rm -f $(OBJETOS) app
