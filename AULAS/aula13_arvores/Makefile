all: app

app: app.o Tree.o
	g++ app.o Tree.o -o $@

app.o: app.cpp
	g++ -c app.cpp

ListDoubleLinked.o: TreeTAD.cpp
	g++ -c TreeTAD.cpp

clean:
	@rm -f app Tree.o app.o
