
all: program1
program1: program1.o Card.o
	g++ -g -o program1 Card.o  program1.o

program1.o: program1.cpp
	g++ -c -g program1.cpp

Card.o: Card.h Card.cpp
	g++ -c Card.cpp -o Card.o

clean: 
	-rm program1.o program1
