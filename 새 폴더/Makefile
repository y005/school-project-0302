run : pa4.o maxSum.o
	g++ -o run pa4.o maxSum.o

score : score.o maxSum.o
	g++ -o score score.o maxSum.o

pa4.o : pa4.cpp
	g++ -c -o pa4.o pa4.cpp

maxSum.o : maxSum.cpp maxSum.h
	g++ -c -o maxSum.o maxSum.cpp

clean :
	rm -f run pa4.o maxSum.o score
