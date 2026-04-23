all: main

main: main.o mergesort.o vetores.o buscaSequencial.o buscaBinaria.o
	g++ -Wall -std=c++17 -o main main.o buscaSequencial.o buscaBinaria.o mergesort.o selectionsort.o vetores.o -Iheaders -o 

main.o: main.cpp
	g++ -Wall -std=c++17 -c main.cpp

buscaSequencial.o: buscaSequencial.cpp
	g++ -Wall -std=c++17 -c buscaSequencial.cpp

buscaBinaria.o: buscaBinaria.cpp
	g++ -Wall -std=c++17 -c buscaBinaria.cpp

mergesort.o: mergesort.cpp
	g++ -Wall -std=c++17 -c mergesort.cpp

selectionsort.o: selectionsort.cpp
	g++ -Wall -std=c++17 -c selectionsort.cpp

vetores.o: vetores.cpp
	g++ -Wall -std=c++17 -c vetores.cpp

clean:
	rm -f main.o mergesort.o selectionsort.o vetores.o buscaSequencial.o buscaBinaria.o main.exe main