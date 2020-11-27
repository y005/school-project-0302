run : main.o inv.o
	g++ -o run main.o inv.o

score : score.o inv.o
	g++ -o score score.o inv.o

main.o : main.cpp
	g++ -c -o main.o main.cpp
inv.o : inv.cpp inv.h
	g++ -c -o inv.o inv.cpp
clean : 
	rm -f run score main.o inv.o
