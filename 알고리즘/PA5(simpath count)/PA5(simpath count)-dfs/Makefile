run : grid.o pa5.o
	g++ -o run pa5.o grid.o

pa5.o : pa5.cpp
	g++ -c -o pa5.o pa5.cpp

grid.o : grid.cpp grid.h
	g++ -c -o grid.o grid.cpp

clean :
	rm -f run pa5.o grid.o
