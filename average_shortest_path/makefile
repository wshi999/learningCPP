all: graph.o
	g++ main.cpp graph.o -o main
	./main.exe

graph.o: graph.cpp graph.hpp
	g++ -c graph.cpp -o graph.o

clean:
	rm -f *.o main