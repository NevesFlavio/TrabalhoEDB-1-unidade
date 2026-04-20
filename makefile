all: main

main: main.o mergesort.o vetores.o
	g++ -Wall -std=c++17 -o main main.o mergesort.o vetores.o

main.o: main.cpp
	g++ -Wall -std=c++17 -c main.cpp

mergesort.o: mergesort.cpp
	g++ -Wall -std=c++17 -c mergesort.cpp

vetores.o: vetores.cpp
	g++ -Wall -std=c++17 -c vetores.cpp

clean:
	rm -f main.o mergesort.o vetores.o main.exe main