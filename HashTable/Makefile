all:main.o hashTable.o
	g++ main.o hashTable.o -o target.out
main.o:main.cpp
	g++ -c main.cpp -o main.o
hashTable.o:hashTable.cpp
	g++ -c hashTable.cpp -o hashTable.o
clean:
	rm *.o
	rm *.out