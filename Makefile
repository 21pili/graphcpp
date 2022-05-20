CPP=g++ -std=c++20
RM=rm -f

graph : Graph.o Edge.o main.o
	$(CPP) $^ -o $@

# vérifiez les dépendances
Edge.o : Edge.cpp Edge.h
Graph.o : Graph.cpp Graph.h
main.o : main.cpp Graph.h

%.o:%.cpp
	$(CPP) -o $@ -c $<

clean:
	$(RM) *.o graph

.PHONY: clean