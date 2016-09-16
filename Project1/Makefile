# Created by Bowenwu
# DS PROJECT ONE

CC= g++ -std=c++11
all:main.o TrainManager.o
	$(CC) main.o TrainManager.o -o main.out
main.o:main.cpp
	$(CC) -c main.cpp -o $@
TrainManager.o:TrainManager.cpp
	$(CC) -c TrainManager.cpp -o $@
clean:
	rm -f *.0
