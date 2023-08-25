.DEFAULT_GOAL := default

default: compile link run clean hello
	
all: compile link run clean

compile:
	g++ --std=c++17 -c $(wildcard *.cpp)

link:
	g++ --std=c++17 -o main $(wildcard *.o)

run:
	./main

clean:
	rm -f *.o 

hello:
	echo "Done!"
