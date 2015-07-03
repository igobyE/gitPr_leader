main: main.o BSTree.o PQueue_list.o
	g++ -o main main.o BSTree.o PQueue_list.o

main.o: main.cpp
	g++ -c -g main.cpp

BSTree.o: BSTree.cpp BSTree.h
	g++ -c -g BSTree.cpp

PQueue_list.o: PQueue_list.cpp PQueue_list.h
	g++ -c -g PQueue_list.cpp

clean:
	rm *o main