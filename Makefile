#Alan Benitez
test: main.o FileReader.o Hashing.o Node.o
	g++ -Wall -o $@ $^
test.o: main.cpp
	g++ -Wall -c main.cpp
FileReader.o: FileReader.hpp FileReader.cpp
	g++ -Wall -c FileReader.cpp
Hashing.o: Hashing.hpp Hashing.cpp
	g++ -Wall -c Hashing.cpp
Node.o:	Node.hpp Node.cpp
	g++ -Wall -c Node.cpp
