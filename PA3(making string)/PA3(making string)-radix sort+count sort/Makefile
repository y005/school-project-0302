run : pa3.o concat.o pri.o
	g++ -o run pa3.o concat.o pri.o

score : score.o concat.o pri.o
	g++ -o score score.o concat.o pri.o

pa3.o : pa3.cpp
	g++ -c -o pa3.o pa3.cpp

concat.o : concat.cpp
	g++ -c -o concat.o concat.cpp

pri.o : pri.cpp
	g++ -c -o pri.o pri.cpp

clean :
	rm -f run pa3.o concat.o pri.o score
