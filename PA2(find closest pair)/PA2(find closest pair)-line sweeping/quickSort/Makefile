run : pa2.o closest.o point.o
	g++ -o run pa2.o closest.o point.o

score : score.o closest.o point.o
	g++ -o score score.o closest.o point.o

pa2.o : pa2.cpp
	g++ -c -o pa2.o pa2.cpp

closest.o : closest.cpp closest.h
	g++ -c -o closest.o closest.cpp

point.o : point.cpp point.h
	g++ -c -o point.o point.cpp

clean :
	rm -f run pa2.o score closest.o point.o
