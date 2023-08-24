all: compile link run

compile:
	g++ --std=c++17 -c $(wildcard *.cpp)

link:
	g++ --std=c++17 -o main $(wildcard *.o)

run:
	./main

run:
	./main