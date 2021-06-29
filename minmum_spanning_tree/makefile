all: graph.o
	g++ main.cpp graph.o -o a
	./a.exe

graph.o: graph.cpp graph.hpp
	g++ -c graph.cpp -o graph.o

clean:
	rm -f *.o a